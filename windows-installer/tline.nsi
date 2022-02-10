!pragma warning error all

Unicode true

# !verbose 4

!define APPNAME "Tline"
!define DESCRIPTION "Tline - a transmission line calculator"

!define ICON "tlineIcon.ico"

!define LICENSE "LICENSE"

!define BITS 32

!searchparse /file ..\version.h `#define VERSION "` VER_MAJOR `.` VER_MINOR `.` VER_BUILD `"`
!define INSTALLSIZE 59610036

!define MUI_WELCOMEPAGE_TITLE "${DESCRIPTION}"
!define MUI_WELCOMEPAGE_TEXT "Version ${VER_MAJOR}.${VER_MINOR}.${VER_BUILD}"

!define MUI_COMPONENTSPAGE_TEXT_DESCRIPTION_INFO "${DESCRIPTION}"

!define MUI_ICON "${ICON}"
!define MUI_UNICON "modern-uninstall-full.ico"

RequestExecutionLevel admin

InstallDir $PROGRAMFILES${BITS}\${APPNAME}

!include "MUI.nsh"
!include "Library.nsh"
!include "FileAssociation.nsh"

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "${LICENSE}"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

!macro VerifyUserIsAdmin
UserInfo::GetAccountType
pop $0
${If} $0 != "admin"
        messageBox mb_iconstop "Administrator rights required!"
        setErrorLevel 740
        quit
${EndIf}
!macroend

function .onInit
	SetShellVarContext all
	!insertmacro VerifyUserIsAdmin
functionEnd

Section -Prerequisites
	SetOutPath $INSTDIR\Prerequisites
	MessageBox MB_YESNO "Tline uses Gnuplot to make its graphs.$\r$\n$\r$\nIf you already have gnuplot installed, you don't have to install it again here.  Click 'NO' to skip installing gnuplot.$\r$\n$\r$\nIf you don't already have gnuplot installed, then click 'YES' to install it.  When installing gnuplot, you generally want to accept all the default settings.$\r$\n$\r$\nInstall Gnuplot?" /SD IDYES IDNO endGnuplot
	File "Prerequisites\gp527-win32-mingw.exe"
	ExecWait "$INSTDIR\Prerequisites\gp527-win32-mingw.exe"
	endGnuplot:
SectionEnd

Name "Tline"
OutFile "tline-installer.exe"

Section "Tline"
	SetOutPath $INSTDIR

	# These land in C:\Program Files (x86)\Tline unless the user overrides the INSTDIR.
	File "tline.exe"
	File "${ICON}"
	File "${LICENSE}"
	File "libgcc_s_dw2-1.dll"
	File "libjpeg-62.dll"
	File "libpng16-16.dll"
	File "libssp-0.dll"
	File "libstdc++-6.dll"
	File "libtiff-5.dll"
	File "libwinpthread-1.dll"
	File "wxbase30u_gcc_custom.dll"
	File "wxmsw30u_core_gcc_custom.dll"
	File "wxmsw30u_html_gcc_custom.dll"
	File "zlib1.dll"
	WriteUninstaller $INSTDIR\uninstall.exe

	CreateDirectory "$SMPROGRAMS\${APPNAME}"
	CreateShortCut "$SMPROGRAMS\${APPNAME}\${APPNAME}.lnk" "$INSTDIR\tline.exe" "" "$INSTDIR\${ICON}"
	CreateShortCut "$SMPROGRAMS\${APPNAME}\uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\${ICON}"

	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayName" "${DESCRIPTION}"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "QuietUninstallString" "$\"$INSTDIR\uninstall.exe$\" /S"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "InstallLocation" "$\"$INSTDIR$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayIcon" "$\"$INSTDIR\logo.ico$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "Publisher" "$\"${APPNAME}$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME} ${APPNAME}" "DisplayVersion" "$\"${VER_MAJOR}.${VER_MINOR}.${VER_BUILD}$\""
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "VersionMajor" ${VER_MAJOR}
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "VersionMinor" ${VER_MINOR}
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "NoModify" 1
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "NoRepair" 1
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "EstimatedSize" ${INSTALLSIZE}

	${registerExtension} "$INSTDIR\tline.exe" ".tline" "TLine File"
SectionEnd

function un.onInit
	SetShellVarContext all

	MessageBox MB_OKCANCEL "Permanantly remove ${APPNAME}?" IDOK next
		Abort
	next:
	!insertmacro VerifyUserIsAdmin
functionEnd

section "uninstall"
	${unregisterExtension} ".tline" "TLine File"

	delete "$SMPROGRAMS\${APPNAME}\uninstall.lnk"
	delete "$SMPROGRAMS\${APPNAME}\${APPNAME}.lnk"
	rmDir "$SMPROGRAMS\${APPNAME}"

	# Remove gnuplot installer.
	rmDir /r "$INSTDIR\Prerequisites"

	delete "$INSTDIR\libgcc_s_dw2-1.dll"
	delete "$INSTDIR\libjpeg-62.dll"
	delete "$INSTDIR\libpng16-16.dll"
	delete "$INSTDIR\libssp-0.dll"
	delete "$INSTDIR\libstdc++-6.dll"
	delete "$INSTDIR\libtiff-5.dll"
	delete "$INSTDIR\libwinpthread-1.dll"
	delete "$INSTDIR\wxbase30u_gcc_custom.dll"
	delete "$INSTDIR\wxmsw30u_core_gcc_custom.dll"
	delete "$INSTDIR\wxmsw30u_html_gcc_custom.dll"
	delete "$INSTDIR\zlib1.dll"
	delete "$INSTDIR\${LICENSE}"
	delete "$INSTDIR\${ICON}"
	delete "$INSTDIR\tline.exe"

	delete $INSTDIR\uninstall.exe

	rmDir $INSTDIR

	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
sectionEnd

Name:           tline
Version:        1.0.4
Release:        1%{?dist}
Epoch:          1
Summary:        Transmission Line calculator

License:        GPLv3+

Source0:        tline-%{version}.tar.gz

BuildRequires:  cmake
BuildRequires:  gcc-c++
BuildRequires:  wxGTK-devel
BuildRequires:  vim-common
BuildRequires:  ImageMagick
BuildRequires:  desktop-file-utils
BuildRequires:  libappstream-glib
BuildRequires:  sed

Requires:       electronics-menu
Requires:       gnuplot-wx
Requires:       xterm


%description
tline is a transmission line calculator


%prep
%setup


%build
%cmake -DDEFAULT_PREFIX_PATH=/usr -DTLINE_STRIP=OFF .
%cmake_build


%install
%cmake_install

# install desktop
for desktopfile in %{buildroot}%{_datadir}/applications/*.desktop ; do
  desktop-file-install \
  --dir %{buildroot}%{_datadir}/applications \
  --remove-category Development              \
  --delete-original                          \
  ${desktopfile}
done


%check
appstream-util validate-relax --nonet %{buildroot}/%{_datadir}/appdata/*.appdata.xml


%files
%{_bindir}/tline
%{_datadir}/appdata/*.xml
%{_datadir}/applications/*.desktop
%{_datadir}/icons/hicolor/*/mimetypes/application-x-*.*
%{_datadir}/icons/hicolor/*/apps/*.*
%{_datadir}/mime/packages/*.xml
%doc doc/equations.pdf
%license LICENSE


%changelog

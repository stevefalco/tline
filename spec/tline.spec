Name:           tline
Version:        1.0.1
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
* Thu Feb 10 2022 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.9-1
- Try again on windows file associations

* Thu Feb 10 2022 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.8-1
- Bump to 0.2.8

* Wed Feb 09 2022 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.7-1
- Correct metadata for .tline files

* Tue Feb 08 2022 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.6-1
- Working on install path control

* Mon Feb 07 2022 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.5-1
- Further Dark Mode

* Mon Feb 07 2022 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.4-1
- Support Dark Mode

* Mon Nov 15 2021 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.3-1
- Update to 0.2.3

* Mon Sep 07 2020 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.2-1
- Update to 0.2.2

* Sat Sep 05 2020 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.1-1
- Update to 0.2.1

* Sat Dec 28 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.2.0-1
- Update to 0.2.0

* Wed Dec 11 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.1.2-1
- Update to 0.1.2

* Wed Oct 09 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.1.1-1
- Update to 0.1.1

* Wed Oct 09 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.1.0-1
- Update to 0.1.0

* Tue Sep 24 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.7-1
- Update to 0.0.7

* Thu Sep 19 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.6-1
- Update to 0.0.6

* Tue Sep 10 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.5-1
- Update to 0.0.5

* Thu Sep 05 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.4-1
- Update to 0.0.4

* Wed Aug 28 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.3-1
- Update to 0.0.3

* Sun Aug 18 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.2-1
- Update to 0.0.2

* Fri Aug 16 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.1-1
- Initial release of 0.0.1


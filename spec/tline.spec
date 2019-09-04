Name:           tline
Version:        0.0.3
Release:        1%{?dist}
Epoch:          1
Summary:        Transmission Line calculator

License:        GPLv3+

Source0:        tline-%{version}.tar.gz

BuildRequires:  cmake
BuildRequires:  gcc-c++
BuildRequires:  wxGTK3-devel
BuildRequires:  vim-common
BuildRequires:  ImageMagick
BuildRequires:  desktop-file-utils
BuildRequires:  libappstream-glib

Requires:       electronics-menu
Requires:       gnuplot-wx


%description
tline is a transmission line calculator


%prep
%setup


%build
mkdir build
cd build
%cmake ..
%make_build


%install
cd build
%make_install

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
* Wed Aug 28 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.3-1
- Update to 0.0.3

* Sun Aug 18 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.2-1
- Update to 0.0.2

* Fri Aug 16 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.1-1
- Initial release of 0.0.1


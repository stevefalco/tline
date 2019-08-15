Name:           tline
Version:        0.0.1
Release:        1%{?dist}
Epoch:          1
Summary:        Transmission Line calculator

License:        GPLv3+

Source0:        tline-%{version}.tar.gz

BuildRequires:  cmake
BuildRequires:  gcc-c++
BuildRequires:  wxGTK3-devel
BuildRequires:  vim-common

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

%files
%{_bindir}/tline
%license LICENSE

%changelog
* Thu Aug 15 2019 Steven A. Falco <stevenfalco@gmail.com> - 1:0.0.1-1
- Initial release of 0.0.1


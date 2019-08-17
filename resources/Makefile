# Copyright 2019 Steven A. Falco <stevenfalco@gmail.com>
# 
# This file is part of tline.
# 
#  tline is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  tline is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with tline.  If not, see <https://www.gnu.org/licenses/>.

GEN_BASE = ../generated-resources/linux

ICON_BASE = ${GEN_BASE}/mime/icons/hicolor

PNG_FILES_128 =								\
	${ICON_BASE}/128x128/apps/tline.png				\
	${ICON_BASE}/128x128/mimetypes/application-x-tline.png		\
	#

PNG_FILES_64 =								\
	${ICON_BASE}/64x64/apps/tline.png				\
	${ICON_BASE}/64x64/mimetypes/application-x-tline.png		\
	#

PNG_FILES_48 =								\
	${ICON_BASE}/48x48/apps/tline.png				\
	${ICON_BASE}/48x48/mimetypes/application-x-tline.png		\
	#

PNG_FILES_32 =								\
	${ICON_BASE}/32x32/apps/tline.png				\
	${ICON_BASE}/32x32/mimetypes/application-x-tline.png		\
	#

PNG_FILES_24 =								\
	${ICON_BASE}/24x24/apps/tline.png				\
	${ICON_BASE}/24x24/mimetypes/application-x-tline.png		\
	#

PNG_FILES_22 =								\
	${ICON_BASE}/22x22/apps/tline.png				\
	${ICON_BASE}/22x22/mimetypes/application-x-tline.png		\
	#

PNG_FILES_16 =								\
	${ICON_BASE}/16x16/apps/tline.png				\
	${ICON_BASE}/16x16/mimetypes/application-x-tline.png		\
	#

PNG_FILES = $(PNG_FILES_128) $(PNG_FILES_64) $(PNG_FILES_48) $(PNG_FILES_32) $(PNG_FILES_24) $(PNG_FILES_22) $(PNG_FILES_16)

SVG_FILES =								\
	${ICON_BASE}/scalable/apps/tline.svg				\
	${ICON_BASE}/scalable/mimetypes/application-x-tline.svg		\
	#

PACK_XML_FILE = ${GEN_BASE}/mime/mime/packages/tline-tline.xml

APP_XML_FILE = ${GEN_BASE}/appdata/tline.appdata.xml

DESKTOP_FILE = ${GEN_BASE}/mime/applications/tline.desktop

XPM_FILE = $(GEN_BASE)/xpm/tlineIcon.xpm

ICO_FILE = ../windows-installer/tlineIcon.ico

all: $(PNG_FILES) $(SVG_FILES) $(PACK_XML_FILE) $(APP_XML_FILE) $(DESKTOP_FILE) $(XPM_FILE) $(ICO_FILE)

$(PNG_FILES_128): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 128x128 $@

$(PNG_FILES_64): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 64x64 $@

$(PNG_FILES_48): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 48x48 $@

$(PNG_FILES_32): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 32x32 $@

$(PNG_FILES_24): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 24x24 $@

$(PNG_FILES_22): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 22x22 $@

$(PNG_FILES_16): tline.svg
	mkdir -p `dirname $@`
	convert $^ -resize 16x16 $@

$(SVG_FILES): tline.svg
	mkdir -p `dirname $@`
	cp $^ $@
	
$(PACK_XML_FILE): tline-tline.xml
	mkdir -p `dirname $@`
	cp $^ $@
	
$(APP_XML_FILE): tline.appdata.xml
	mkdir -p `dirname $@`
	cp $^ $@
	
$(DESKTOP_FILE): tline.desktop
	mkdir -p `dirname $@`
	cp $^ $@
	
$(XPM_FILE): tline.svg
	mkdir -p `dirname $@`
	convert $^ $@
	sed -i -e 's/^static char \*tlineIcon\[] = {$$/char const * aaaa_xpm[] = {/' $@

$(ICO_FILE): tline.svg
	convert $^ -bordercolor white -border 0		\
		\( -clone 0 -resize 16x16 \)		\
		\( -clone 0 -resize 32x32 \)		\
		\( -clone 0 -resize 48x48 \)		\
		\( -clone 0 -resize 57x57 \)		\
		\( -clone 0 -resize 64x64 \)		\
		\( -clone 0 -resize 72x72 \)		\
		\( -clone 0 -resize 110x110 \)		\
		\( -clone 0 -resize 114x114 \)		\
		\( -clone 0 -resize 120x120 \)		\
		\( -clone 0 -resize 128x128 \)		\
		\( -clone 0 -resize 144x144 \)		\
		\( -clone 0 -resize 152x152 \)		\
		-delete 0 -alpha off -colors 256	\
		$@


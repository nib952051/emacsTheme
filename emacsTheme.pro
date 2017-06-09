TEMPLATE = lib
TARGET = emacsTheme
CONFIG += console warn_on plugin
QT = core gui core-private gui-private theme_support-private

SOURCES += ./emacsTheme.cpp
OTHER_FILES += emacs.json README.md

emacsPlugin.path = $$[QT_INSTALL_LIBS]/../plugins/platformthemes/
emacsPlugin.files = libemacsTheme.so
INSTALLS += emacsPlugin

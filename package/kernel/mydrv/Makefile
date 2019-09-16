#
#
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

PKG_NAME:=mydrv
PKG_RELEASE:=1

define KernelPackage/mydrv
  SUBMENU:=Other modules
  TITLE:=mydrv
  FILES:=$(PKG_BUILD_DIR)/mydrv.ko
  KCONFIG:=
endef

define KernelPackage/mydrv/description
  This is a mydrv drivers
endef

MAKE_OPTS:= \
	ARCH="$(LINUX_KARCH)" \
	CROSS_COMPILE="$(TARGET_CROSS)" \
	SUBDIRS="$(PKG_BUILD_DIR)"

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
	$(MAKE_OPTS) modules
endef

$(eval $(call KernelPackage,mydrv))

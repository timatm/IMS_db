NVME_LIB_ARGS = --default-library=static

all: nvme-clean nvme-setup nvme-build 

nvme-setup:
	cd libnvme && meson setup .build $(NVME_LIB_ARGS)
	@echo "Configuration located in: libnvme/.build"
	@echo "-------------------------------------------------------"	
	@echo "To build, run: make nvme-build"

nvme-build:
	cd libnvme && meson compile -C .build

nvme-test:
	cd libnvme && meson test -C .build
	@echo "To run the tests, run: make nvme-test"

nvme-clean:
	cd libnvme && meson compile --clean -C .build
	@echo "To clean the build, run: make nvme-clean"
	@echo "To remove the build directory, run: make nvme-purge"

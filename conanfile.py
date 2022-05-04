from conans import ConanFile, CMake

class KvasirMpl(ConanFile):
	name = "Mpl"
	version = "3.0"
	exports_sources = "*"
	no_copy_source = True

	def _configure_cmake(self):
		cmake = CMake(self)
		cmake.configure()
		return cmake

	def package(self):
		cmake = self._configure_cmake()
		cmake.install()

	def package_id(self):
		self.info.header_only()
			

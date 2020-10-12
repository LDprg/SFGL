find_package(Doxygen REQUIRED)

add_custom_target(doc ALL
    	        COMMAND ${DOXYGEN_EXECUTABLE} ./config.doxy
                DEPENDS SFGL)
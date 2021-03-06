INCLUDE_DIRECTORIES(../c/) # used by FrontEnd::readLibrarySignatures
SET(SRC
    frontend.cpp
    TargetQueue.cpp
    MachineInstruction
    njmcDecoder.cpp
    njmcDecoder.h
    pentium/pentiumdecoder.cpp #-fno-exceptions
    pentium/pentiumfrontend.cpp
    ppc/ppcdecoder.cpp
    ppc/ppcfrontend.cpp
    sparc/sparcdecoder.cpp
    sparc/sparcdecoder.h
    sparc/sparcfrontend.cpp
    sparc/sparcfrontend.h
#    mc68k/m68kfrontend.cpp
#    mc68k/m68kdecoder.cpp
    mips/mipsdecoder.cpp
    mips/mipsdecoder.h
    mips/mipsfrontend.cpp
    mips/mipsfrontend.h
    st20/st20decoder.cpp
    st20/st20decoder.h
    st20/st20frontend.cpp
    st20/st20frontend.h
)
set(SSL_FILES
  machine/st20/st20.ssl
  machine/mips/mips.ssl
  machine/hppa/hppa.ssl
  machine/pentium/pentium.ssl
  machine/ppc/ppc.ssl
  machine/sparc/sparc.ssl
)

foreach( ssl_file ${SSL_FILES} )
  add_custom_command(
    OUTPUT "${PROJECT_SOURCE_DIR}/out/frontend/${ssl_file}"
    COMMAND cmake -E copy
    "${CMAKE_CURRENT_SOURCE_DIR}/${ssl_file}"
    "${PROJECT_SOURCE_DIR}/out/frontend/${ssl_file}"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${ssl_file}"
  )
  list( APPEND ssl_files_dest "${PROJECT_SOURCE_DIR}/out/frontend/${ssl_file}" )
endforeach()
add_custom_target( CopySSLs ALL DEPENDS ${ssl_files_dest} )

ADD_LIBRARY(frontend STATIC ${SRC})
add_dependencies(frontend CopySSLs)
qt5_use_modules(frontend Core)

IF(BUILD_TESTING)
ADD_SUBDIRECTORY(unit_testing)
ENDIF()

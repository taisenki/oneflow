include (ExternalProject)

if (WITH_TVM)

set(TVM_DIR ${CMAKE_CURRENT_BINARY_DIR}/third_party/tvm)
set(TVM_SOURCES_DIR ${TVM_DIR}/src/tvm)
set(TVM_GIT_URL https://github.com/apache/incubator-tvm.git) 
set(TVM_GIT_TAG c6f8c23c349f3ef8bacceaf3203f7cc08e6529de) # tag 0.6.0

set(TVM_INSTALL_DIR ${THIRD_PARTY_DIR}/tvm)

if (THIRD_PARTY)

  ExternalProject_Add(tvm
    PREFIX ${TVM_DIR}
    GIT_REPOSITORY ${TVM_GIT_URL}
    GIT_TAG ${TVM_GIT_TAG}
    CMAKE_CACHE_ARGS
        -DCMAKE_INSTALL_PREFIX:STRING=${TVM_INSTALL_DIR}
        -DINSTALL_DEV:BOOL=ON
    BUILD_COMMAND cd ${TVM_SOURCES_DIR} && mkdir -p build
      && cp cmake/config.cmake build && cd build && cmake .. && make -j32
    LOG_DOWNLOAD ON)

endif(THIRD_PARTY)

endif(WITH_TVM)

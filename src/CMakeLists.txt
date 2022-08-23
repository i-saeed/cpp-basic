set(
  HEADER_FILES
    doublelinkedlist.h
    linkedlist.h
    binarytree.h
)

add_library(
    basic_data_structures
    INTERFACE
    ${HEADER_FILES}
  )

target_include_directories(basic_data_structures
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>  # <prefix>/include/mylib
  )

#########################################
add_library(
    utils
  SHARED
    utils.cpp
)

target_include_directories(utils
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>  # <prefix>/include/mylib
  )


# target_sources(myHeaderOnly
#     PUBLIC
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/algo.h>
#         $<INSTALL_INTERFACE:include/algo.h>
# )
# install(FILES algo.h DESTINATION include)

#################################
add_executable(test_linked_list
  test_linked_list.cpp
)

add_dependencies(test_linked_list basic_data_structures)
target_link_libraries(
    test_linked_list
  PRIVATE
    basic_data_structures
)

#################################
add_executable(test_double_linked_list
  test_double_linked_list.cpp
)

add_dependencies(test_double_linked_list basic_data_structures)
target_link_libraries(
    test_double_linked_list
  PRIVATE
    basic_data_structures
)

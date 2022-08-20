#################################
add_executable(test_linked_list test_linked_list.cpp)

add_dependencies(test_linked_list basic_data_structures)
target_link_libraries(
    test_linked_list
  PRIVATE
    basic_data_structures
)

#################################
add_executable(test_double_linked_list test_double_linked_list.cpp)

add_dependencies(test_double_linked_list basic_data_structures)
target_link_libraries(
    test_double_linked_list
  PRIVATE
    basic_data_structures
)


#################################
add_executable(reverse_linkedlist reverse_linkedlist.cpp)

add_dependencies(reverse_linkedlist basic_data_structures)
target_link_libraries(
    reverse_linkedlist
  PRIVATE
    basic_data_structures
)


#################################
add_executable(merge_sorted_linked_lists merge_sorted_linked_lists.cpp)

add_dependencies(merge_sorted_linked_lists merge_sorted_linked_lists)
target_link_libraries(
    merge_sorted_linked_lists
  PRIVATE
    basic_data_structures
)

target_compile_options(
  merge_sorted_linked_lists
  PUBLIC
  -g3
)

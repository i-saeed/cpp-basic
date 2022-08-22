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
add_executable(queue_using_stacks queue_using_stacks.cpp)

add_dependencies(queue_using_stacks queue_using_stacks)
target_link_libraries(
    queue_using_stacks
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

add_dependencies(merge_sorted_linked_lists basic_data_structures)
target_link_libraries(
    merge_sorted_linked_lists
  PRIVATE
    basic_data_structures
)

#################################
add_executable(cycle_linked_list cycle_linked_list.cpp)

add_dependencies(cycle_linked_list  basic_data_structures)
target_link_libraries(
    cycle_linked_list
  PRIVATE
    basic_data_structures
)

target_compile_options(
  cycle_linked_list
  PUBLIC
  -g3
)

#################################
add_executable(contains_duplicate contains_duplicate.cpp)

add_dependencies(contains_duplicate  utils)
target_link_libraries(
    contains_duplicate
  PRIVATE
    utils
)

#################################
add_executable(checks_anagram checks_anagram.cpp)

add_dependencies(checks_anagram  utils)
target_link_libraries(
    checks_anagram
  PRIVATE
    utils
)

#################################
add_executable(two_sums two_sums.cpp)

add_dependencies(two_sums  utils)
target_link_libraries(
    two_sums
  PRIVATE
    utils
)

#################################
add_executable(palindrome palindrome.cpp)

add_dependencies(palindrome  utils)
target_link_libraries(
    palindrome
  PRIVATE
    utils
)

#################################
add_executable(valid_parentheses valid_parentheses.cpp)

add_dependencies(valid_parentheses utils)
target_link_libraries(
    valid_parentheses
  PRIVATE
    utils
)

#################################
add_executable(max_profit_stocks max_profit_stocks.cpp)

add_dependencies(max_profit_stocks utils)
target_link_libraries(
    max_profit_stocks
  PRIVATE
    utils
)

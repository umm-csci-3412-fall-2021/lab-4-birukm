cmake_minimum_required(VERSION 3.20)
project(lab_4_birukm)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_4_birukm
        file_disemvowel/tests/file_disemvowel.c
        file_disemvowel/file_disemvowel.c
        summarize_tree/test_data/large_dir_sizes
        summarize_tree/test_data/small_dir_sizes
        summarize_tree/test_data/test_data.tgz
        summarize_tree/summarize_tree.c
        summarize_tree/summarize_tree_ftw.c
        summarize_tree/summarize_tree_test.bats)

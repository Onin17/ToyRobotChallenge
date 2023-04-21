function(unit_test testname)
    add_executable(${testname} ${testname})
    target_link_libraries(${testname} ToyRobotChallenge)
    add_test(${testname} ${testname})
endfunction()

unit_test(robot_test)

remake_find_package(carmen-core CONFIG)
remake_find_package(carmen-interface CONFIG)
remake_find_package(tulibs CONFIG)
remake_find_package(era-libs CONFIG)

remake_define(REDHAT_52 ON)
remake_define(REDHAT_6 ON)
remake_define(REDHAT_71 ON)

remake_include(${ERA_LIBS_INCLUDE_DIRS})

remake_add_directories()

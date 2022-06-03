# [Usage]
# build project: `make build`
# run project: `make` or `make run`
# debug project: `make debug`
# clean build folder: `make clean`

# [Info]

# Project
QUESTION = 929
PROJECT_FOLDER = PROJECTS
SOURCE = ./${PROJECT_FOLDER}/${QUESTION}/main.cpp
# Build
BUILD_FOLDER = build
EXECUTABLE = ./${BUILD_FOLDER}/release.out
EXECUTABLE_DEBUG = ./${BUILD_FOLDER}/debug.out
# Tools
COMPILER = clang++
DEBUGER = lldb # https://lldb.llvm.org/use/tutorial.html
CFLAGS = -std=c++17 -W -Wall
# `-std=<value>`
#     Language standard to compile for
#     Check https://clang.llvm.org/c_status.html
# `-g`
#     Generate source-level debug information
# `-W -Wall`
#     "Put -W -Wall in your build flags. The Clang devs will take care of making sure this is a sensible warning level for all codebases, including yours." -- https://quuxplusone.github.io/blog/2018/12/06/dont-use-weverything/
# `-O2`
#     "-O2 is a moderate level of optimization which enables most optimizations." -- https://stackoverflow.com/a/21450534/14298786

# [Target]

# Debug
build-debug: create-build-folder ${SOURCE}
	@${COMPILER} ${SOURCE} -o ${EXECUTABLE_DEBUG} ${CFLAGS} -g 
debug: build-debug
	@${DEBUGER} ${EXECUTABLE_DEBUG}

# Run
build: create-build-folder ${SOURCE}
	@${COMPILER} ${SOURCE} -o ${EXECUTABLE} ${CFLAGS} -O2
run: build
	@${EXECUTABLE} ${ARGUMENTS}

# Others
create-build-folder:
	@mkdir -p ${BUILD_FOLDER} 
clean:
	@rm -rf ${BUILD_FOLDER}

# [Config]
.PHONY = build-debug debug build run create-build-folder clean 
.DEFAULT_GOAL = run

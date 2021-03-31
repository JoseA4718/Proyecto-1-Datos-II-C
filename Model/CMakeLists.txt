cmake_minimum_required(VERSION 3.17)
project(Model)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
add_executable(Model src/main.cpp src/Types/GenericType.h src/Types/Int/Integer.cpp src/Types/Int/Integer.h src/Types/Char/Char.cpp src/Types/Char/Char.h src/Types/Double/Double.cpp src/Types/Double/Double.h src/Types/Float/Float.cpp src/Types/Float/Float.h src/Types/Long/Long.cpp src/Types/Long/Long.h src/Types/Reference/Reference.cpp src/Types/Reference/Reference.h src/Types/Constants.h src/Util/Json.h)



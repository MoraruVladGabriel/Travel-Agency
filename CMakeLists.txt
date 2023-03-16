cmake_minimum_required(VERSION 3.22)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project1)

add_executable(Project1
        Project1/App.cpp
        Project1/Bilet.cpp
        Project1/Bilet.h
        Project1/IRepository.h
        Project1/RepositoryFile.h
        Project1/RepositoryFileCSV.h
        Project1/RepositoryFileTXT.cpp
        Project1/RepositoryFileTXT.h
        Project1/RepositoryInMemory.cpp
        Project1/RepositoryInMemory.h
        Project1/Service.cpp
        Project1/Service.h
        Project1/TestRepo.cpp
        Project1/TestRepo.h
        Project1/UI.cpp
        Project1/UI.h
        Project1/User.cpp
        Project1/User.h
        Project1/Utils.cpp
        Project1/Utils.h
        Project1/Zbor.cpp
        Project1/Zbor.h)

ADD_LIBRARY(Conversion
Regex.cpp
RegexCreator.cpp
State.cpp
DFAConverter.cpp 
NFAConverter.cpp
)

ADD_EXECUTABLE(DFANFAConverter main.cpp)

target_link_libraries(DFANFAConverter PUBLIC Conversion)
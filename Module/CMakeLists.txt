cmake_minimum_required(VERSION 3.27)

add_subdirectory(AudioModule)
add_subdirectory(CrashModule)
add_subdirectory(FileModule)
add_subdirectory(MathModule)
add_subdirectory(PlatformModule)
add_subdirectory(RenderModule)

set_target_properties(AudioModule CrashModule FileModule MathModule PlatformModule RenderModule PROPERTIES FOLDER "Module")
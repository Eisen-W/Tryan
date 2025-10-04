if(NOT EXISTS "/media/eisn/BC02237702233634/NISARG_NEW/Github_Repo/Raylib_Testing/Tryan/build/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: /media/eisn/BC02237702233634/NISARG_NEW/Github_Repo/Raylib_Testing/Tryan/build/install_manifest.txt")
endif()

file(READ "/media/eisn/BC02237702233634/NISARG_NEW/Github_Repo/Raylib_Testing/Tryan/build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/usr/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif()
  else(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif()
endforeach()

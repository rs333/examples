foreach( PROG one two three four five six seven eight )
  add_executable( crazymacro_${PROG} crazymacros.c  )
  target_compile_definitions(crazymacro_${PROG} PUBLIC PROG=${PROG})
endforeach()

file(REMOVE_RECURSE
  "../devel/lib/libalb_msgs.pdb"
  "../devel/lib/libalb_msgs.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/alb_msgs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

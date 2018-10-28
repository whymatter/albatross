file(REMOVE_RECURSE
  "../devel/lib/libalb_base.pdb"
  "../devel/lib/libalb_base.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/alb_base.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

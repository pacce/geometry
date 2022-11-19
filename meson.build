project('geometry', 'cpp', version : '0.1.0', default_options : ['warning_level=3', 'cpp_std=c++20'])

includes      = include_directories('include')
dependencies  = []

geometry = library(
  meson.project_name()
  , []
  , include_directories : includes
  , dependencies        : dependencies
  , install             : true
  )

geometry_dep = declare_dependency(link_with: geometry, include_directories: includes)

if not meson.is_subproject()
  subdir('tests')
endif

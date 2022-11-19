rapidcheck    = dependency('rapidcheck')
gtest         = dependency('gtest')
dependencies  = [gtest, rapidcheck, geometry_dep]

bidimensional = executable('bidimensional', 'bidimensional.cpp', dependencies: dependencies)

test('bidimensional', bidimensional)

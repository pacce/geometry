rapidcheck    = dependency('rapidcheck')
gtest         = dependency('gtest')
dependencies  = [gtest, rapidcheck, geometry_dep]

bidimensional   = executable('bidimensional', 'bidimensional.cpp', dependencies: dependencies)
tridimensional  = executable('tridimensional', 'tridimensional.cpp', dependencies: dependencies)

test( 'bidimensional',  bidimensional)
test('tridimensional', tridimensional)

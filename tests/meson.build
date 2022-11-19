rapidcheck    = dependency('rapidcheck')
gtest         = dependency('gtest')
dependencies  = [gtest, rapidcheck, geometry_dep]

basic = executable('basic', 'basic.cpp', dependencies: dependencies)

test('basic', basic)

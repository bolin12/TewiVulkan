#.rst:
# FindGLM
# --------
#
# Find the path to the GLM source tree
#
# Minimal search, checks CMAKE_PREFIX_PATH env var only
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
# ::
#
#   GLM_PATH - Path to the GLM source tree
#   GLM_FOUND - true if GLM has been found and can be used

find_path(GLM_PATH
  NAMES glm/glm.hpp
  PATHS ENV CMAKE_PREFIX_PATH
        ${CMAKE_THIRD_PARTY_DIR}/glm
  PATH_SUFFIXES "glm"
)

include_directories(${GLM_PATH})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLM REQUIRED_VARS GLM_PATH)

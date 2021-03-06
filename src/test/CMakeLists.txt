set(GTEST_FOUND "")
find_package(GTest QUIET)

if(GTEST_FOUND)
  message("GTEST found, unit testing is enabled") 
  set(EXECUTABLE_OUTPUT_PATH ${HEATSIM_BINARY_DIR}/test)
  include_directories(${GTEST_INCLUDE_DIRS})

FIND_LIBRARY(GMOCK_LIBRARIES gmock
    HINTS
        $ENV{GMOCK_ROOT}
        ${GMOCK_ROOT}
		$ENV{GMOCK_ROOT}/make
        ${GMOCK_ROOT}/make
)
if(NOT DEFINED GMOCK_LIBRARIES)
	MESSAGE(SEND_ERROR "Google mock library path not Set to GMOCK_LIBRARIES")
endif()

find_path(GMOCK_INCLUDE_DIR gmock/gmock.h
    HINTS
        $ENV{GMOCK_ROOT}/include
        ${GMOCK_ROOT}/include
)
if(NOT DEFINED GMOCK_INCLUDE_DIR)
	MESSAGE(SEND_ERROR "Google mock include path not set to GMOCK_INCLUDE_DIR")	
endif()	

  set(SRC_DIR ${HEATSIM_SOURCE_DIR}/src)
  include_directories(${SRC_DIR})

  add_executable(heatSimTest
      TersoffPotentialTest.cpp
      ${SRC_DIR}/TersoffPotential.cpp
      ${SRC_DIR}/TersoffBond.cpp
      DispersionCurveWriterTest.cpp
      ${SRC_DIR}/DispersionCurveWriter.cpp
      CoordinatesTest.cpp
      ${SRC_DIR}/Location.cpp
      ${SRC_DIR}/Coordinates.cpp
      MatrixTest.cpp
      ${SRC_DIR}/Matrix.cpp
      ${SRC_DIR}/EigenvalueSolution.cpp
      NeighborListTest.cpp
      ${SRC_DIR}/NeighborList.cpp
      POSCARReaderTest.cpp
      ${SRC_DIR}/POSCARReader.cpp
      GeStructureBuilderTest.cpp
      ${SRC_DIR}/Structure.cpp
      ${SRC_DIR}/GeStructureBuilder.cpp
      ${SRC_DIR}/LatticeVectors.cpp
      ${SRC_DIR}/Displacement.cpp
      BondGeometryTest.cpp
      DimerTestStructure.cpp
      ${SRC_DIR}/BondList.cpp
      ${SRC_DIR}/BondGeometry.cpp
      AtomIteratorTest.cpp
      ${SRC_DIR}/AtomIterator.cpp
      ${SRC_DIR}/Atom.cpp
      TotalEnergyTest.cpp
      ${SRC_DIR}/TotalEnergy.cpp
      DimerSpringPotential.cpp
      DynamicalMatrixTest.cpp
      ${SRC_DIR}/DynamicalMatrix.cpp
      ${SRC_DIR}/KVector.cpp 
      LatticeVectorsTest.cpp
      ReciprocalLatticeVectorsTest.cpp
      ${SRC_DIR}/ReciprocalLatticeVectors.cpp
  )
  target_link_libraries(heatSimTest ${GTEST_BOTH_LIBRARIES} -lpthread)
  
  target_link_libraries(heatSimTest ${BLAS_LIB})
  target_link_libraries(heatSimTest ${LAPACK_LIB})
  if (EXISTS ${LIBF2C_LIB})
    target_link_libraries(heatSimTest ${LIBF2C_LIB})
  endif()

else()
  message(AUTHOR_WARNING "** GTEST not found, unit testing not enabled") 
endif(GTEST_FOUND)

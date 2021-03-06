############################################################################
# CMakeLists.txt file for building ROOT io/io package
############################################################################

include_directories(${CMAKE_SOURCE_DIR}/hist/hist/inc)  # Explicit to avoid circular dependencies mathcore <--> hist :-(

set(MATHCORE_HEADERS TRandom.h
  TRandom1.h TRandom2.h TRandom3.h TKDTree.h TKDTreeBinning.h TStatistic.h
  Math/IParamFunction.h Math/IFunction.h Math/ParamFunctor.h Math/Functor.h
  Math/Minimizer.h Math/MinimizerOptions.h Math/IntegratorOptions.h Math/IOptions.h Math/GenAlgoOptions.h
  Math/BasicMinimizer.h Math/MinimTransformFunction.h Math/MinimTransformVariable.h
  Math/Integrator.h Math/VirtualIntegrator.h Math/AllIntegrationTypes.h Math/AdaptiveIntegratorMultiDim.h
  Math/IntegratorMultiDim.h Math/Factory.h Math/FitMethodFunction.h Math/GaussIntegrator.h
  Math/GaussLegendreIntegrator.h Math/RootFinder.h Math/IRootFinderMethod.h Math/RichardsonDerivator.h
  Math/BrentMethods.h Math/BrentMinimizer1D.h Math/BrentRootFinder.h Math/DistSampler.h
  Math/DistSamplerOptions.h Math/GoFTest.h Math/SpecFuncMathCore.h Math/DistFuncMathCore.h
  Math/ChebyshevPol.h Math/KDTree.h Math/TDataPoint.h Math/TDataPointN.h Math/Delaunay2D.h
  Math/Random.h Math/TRandomEngine.h Math/RandomFunctions.h Math/StdRandomEngines.h
  Math/MersenneTwisterEngine.h Math/MixMaxEngine.h 
)


# ROOT_GENERATE_DICTIONARY(G__Math     TComplex.h TMath.h  LINKDEF LinkDef1.h)
# ROOT_GENERATE_DICTIONARY(G__MathCore ${MATHCORE_HEADERS} LINKDEF LinkDef2.h)
# ROOT_GENERATE_DICTIONARY(G__MathFit  Fit/*.h LINKDEF LinkDef3.h)

ROOT_GENERATE_DICTIONARY(G__MathCore   TComplex.h TMath.h ${MATHCORE_HEADERS} Fit/*.h MODULE MathCore LINKDEF LinkDef.h OPTIONS "-writeEmptyRootPCM")



add_definitions(-DUSE_ROOT_ERROR )

#ROOT_LINKER_LIBRARY(MathCore *.cxx G__Math.cxx G__MathCore.cxx G__MathFit.cxx LIBRARIES ${CMAKE_THREAD_LIBS_INIT} DEPENDENCIES Core)

#use this in case of CGAL
#find_package(CGAL)  
#ROOT_LINKER_LIBRARY(MathCore *.cxx *.c G__MathCore.cxx LIBRARIES ${CMAKE_THREAD_LIBS_INIT} DEPENDENCIES Core ${CGAL_LIBRARY} ${GMP_LIBRARIES})
#

ROOT_LINKER_LIBRARY(MathCore *.cxx *.c G__MathCore.cxx LIBRARIES ${CMAKE_THREAD_LIBS_INIT} DEPENDENCIES Core)

ROOT_INSTALL_HEADERS()

ROOT_ADD_TEST_SUBDIRECTORY(test)





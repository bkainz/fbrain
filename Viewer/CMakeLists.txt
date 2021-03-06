PROJECT(Viewer)
INCLUDE_REGULAR_EXPRESSION("^.*$")

INCLUDE_DIRECTORIES(
    ${TCLAP_DIRECTORY}
    ${Code_SOURCE_DIR}/Diffusion
    ${Code_SOURCE_DIR}/ImageFilters
    ${Code_SOURCE_DIR}/Tools
    ${Code_SOURCE_DIR}/Maths
    ${Code_SOURCE_DIR}/Transformations
    ${Code_SOURCE_DIR}/Visualization
)
link_directories(${ITK_DIR}/lib/${CMAKE_CFG_INTDIR})

ADD_EXECUTABLE( btkSlicesMotionViewer btkSlicesMotionViewer.cxx
${Code_SOURCE_DIR}/Visualization/btkRenderPolydata.cxx
${Code_SOURCE_DIR}/Visualization/btkRenderPolydata.h)
TARGET_LINK_LIBRARIES(btkSlicesMotionViewer btkMathsLibrary ${ITK_LIBRARIES} vtkHybrid)

ADD_EXECUTABLE(btkDiffusionViewer btkDiffusionViewer.cxx)
TARGET_LINK_LIBRARIES(btkDiffusionViewer btkToolsLibrary btkDiffusionLibrary ${ITK_LIBARIES} vtkHybrid vtkWidgets)

INSTALL(TARGETS btkSlicesMotionViewer
        btkDiffusionViewer
        DESTINATION bin)


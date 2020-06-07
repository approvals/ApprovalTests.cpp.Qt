from scripts.project_details import ProjectDetails


def qt_project_details() -> ProjectDetails:
    details = ProjectDetails(
        github_project_name='ApprovalTests.cpp.Qt',
        library_folder_name='ApprovalTestsQt',
        simulated_single_header_file='ApprovalTestsQt.hpp',
        version_header='ApprovalTestsQtVersion.h',
        macro_prefix='APPROVAL_TESTS_QT',
        conan_directory_name='approvaltests.cpp.qt',
        update_documentation=False,
        update_conan=False)
    return details

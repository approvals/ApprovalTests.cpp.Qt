import os

from approvaltests.reporters import GenericDiffReporterFactory

diff_merge_reporter = GenericDiffReporterFactory().get("DiffMerge")

def set_home_directory() -> None:
    current_dir = os.getcwd().replace('\\', '/')
    if current_dir.endswith('ApprovalTests.cpp.Qt/ApprovalTestsQt'):
        return
    source_dir = os.path.split(__file__)[0]
    library_dir = os.path.join(source_dir, "../../ApprovalTestsQt")
    os.chdir(library_dir)

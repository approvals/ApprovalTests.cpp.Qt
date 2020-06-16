import sys


def get_path_to_approvals_scripts() -> str:
    import os
    return os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../../ApprovalTests.cpp/build')


sys.path.append(get_path_to_approvals_scripts())

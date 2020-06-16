import unittest

import scripts_qt.include_approvals_path # Note This is used!

from scripts.conan_release import PrepareConanRelease
from scripts.version import Version
from scripts_qt.qt_project_details import qt_project_details


class TestConanRelease(unittest.TestCase):
    def test_get_new_branch_name(self) -> None:
        self.assertEqual('approvaltests.cpp.qt.1.2.3',
                         PrepareConanRelease.get_new_branch_name(qt_project_details(), Version(1, 2, 3)))

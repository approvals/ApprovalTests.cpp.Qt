import unittest

import sys

sys.path.append('../../../ApprovalTests.cpp/build')

from approvaltests.approvals import verify_file, verify_as_json

from scripts_qt.qt_project_details import qt_project_details
from scripts.code_generation import CppGeneration
from scripts.release_details import ReleaseDetails
from scripts.version import Version
from tests.helpers import set_home_directory


class TestForLocking(unittest.TestCase):

    def test_create_single_header_file_approvals(self) -> None:
        prepare_release = self.get_prepare_release()
        output = prepare_release.create_single_header_file()

        # The output of this depends on the current C++ code, so changes
        # over time. It is here to help when refactoring the release process.
        verify_file(output)

    def test_create_simulated_single_header_file(self) -> None:
        prepare_release = self.get_prepare_release()
        output = prepare_release.create_simulated_single_header_file()

        # The output of this depends on the current C++ code, so changes
        # over time. It is here to help when refactoring the release process.
        verify_file(output)

    def test_qt_project_details(self) -> None:
        verify_as_json(qt_project_details())

    def test_release_details(self) -> None:
        verify_as_json(self.get_prepare_release().details)

    def get_prepare_release(self) -> CppGeneration:
        set_home_directory()
        old_version = Version(0, 0, 1)
        new_version = Version(0, 1, 0)
        deploy = False
        release_details = ReleaseDetails(old_version, new_version, deploy, qt_project_details())
        return CppGeneration(release_details)

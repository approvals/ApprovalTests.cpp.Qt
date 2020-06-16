import unittest

from scripts.conan_release import PrepareConanRelease
from scripts.version import Version


class TestConanRelease(unittest.TestCase):
    def test_get_new_branch_name(self) -> None:
        self.assertEqual('approvaltests.cpp.1.2.3', PrepareConanRelease.get_new_branch_name(Version(1, 2, 3)))


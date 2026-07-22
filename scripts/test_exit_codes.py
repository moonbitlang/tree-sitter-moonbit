import runpy
import unittest
from unittest.mock import Mock, patch


class ScriptExitCodeTests(unittest.TestCase):
    def test_generate_exits_with_first_child_failure(self):
        processes = [Mock(), Mock(), Mock()]
        processes[0].wait.return_value = 0
        processes[1].wait.return_value = 7
        processes[2].wait.return_value = 9

        with patch("subprocess.Popen", side_effect=processes):
            with self.assertRaises(SystemExit) as result:
                runpy.run_path("scripts/generate.py", run_name="__main__")

        self.assertEqual(result.exception.code, 7)
        for process in processes:
            process.wait.assert_called_once_with()

    def test_test_exits_with_first_child_failure(self):
        processes = [Mock(), Mock(), Mock()]
        processes[0].wait.return_value = 3
        processes[1].wait.return_value = 0
        processes[2].wait.return_value = 5

        with patch("subprocess.Popen", side_effect=processes):
            with self.assertRaises(SystemExit) as result:
                runpy.run_path("scripts/test.py", run_name="__main__")

        self.assertEqual(result.exception.code, 3)
        for process in processes:
            process.wait.assert_called_once_with()


if __name__ == "__main__":
    unittest.main()

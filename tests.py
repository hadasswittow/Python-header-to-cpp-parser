import unittest
from htocpp import buildCpp

class MyTestCase(unittest.TestCase):
    def test_something(self):
        #self.assertEqual(True, False)
        buildCpp(r"C:\Users\USER\PycharmProjects\htocpp\my_timer.h")


if __name__ == '__main__':
    unittest.main()

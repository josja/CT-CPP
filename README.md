# CT-CPP
C++ Code Task

Task template:
```cpp
class MyClass
{
  public:
  getNiCount(...)
  {
  }

  replaceNiWithNI(...)
  {
  }
};

int main()
{
  const char *szTestString1 = "Ni nI NI nI Ni";
  const wchar_t *szTestString2 = L"Ni nI NI nI Ni";

  // Invoke getNiCount(...) of class MyClass
  // Invoke replaceNiWithNI(...) of class MyClass
  // Display on screen: "Found X occurrences of Ni. New string: Y"
}
```

Task description:

1. Implement the two functions getNiCount and replaceNiWithNI of the class MyClass:
- getNiCount should return the number of occurrences of "Ni" within szTestString1/2 (case sensitive)
- replaceNiWithNI should replace all occurrences of "Ni" in szTestString1/2 with "NI" (case sensitive)

2. Invoke the two functions getNiCount and replaceNiWithNI.

3. Display the string given in the last comment on screen. X and Y should be replaced with the real values.

4. The class MyClass should be able to deal with both szTestString1 (ASCII) and szTestString2 (Unicode).

General requirements:

The code should be
- easy to understand and maintain (Priority 1)
- technically elegant (Priority 2)
- as (CPU) efficient as possible (Priority 3)

You’re allowed to use all technics, toolkits and frameworks which are based on the C++ language.

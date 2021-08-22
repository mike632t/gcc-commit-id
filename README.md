# gcc-commit-id - Display program version with commit id
 
Copyright(C) 2021 - MT

Demonstrates how to display the git commit ID in the program version.

By including the following line in .gitattributes the '$Format:%h$' symbol is automatically updated when the file is copied to the working directory. 

    gcc-commit-id.h   export-subst


References

- https://git-scm.com/book/en/v2/Customizing-Git-Git-Attributes

*This project has been created as part of the 42 curriculum by msowinsk*

# Description
Libft is a library made for 42cursus as the first project.  
Libft goal is to reimplement a set of functions from the `libc` and add few useful ones not included in it.

<details>
	<summary>
		Detailed description
	</summary>

<details>
	<summary>Functions from libc</summary>

### 1. Character handling
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **int** ft_isalpha(int **c**) | **c**: character to be tested | 1 if there is match<br>0 if not | Check if given character is an alphabetic character [a-zA-z] |
| **int** ft_isdigit(int **c**) | **c**: character to be tested | 1 if there is match<br>&nbsp;0 if not | Check if given character is a digit [0-9] |
| **int** ft_isalnum(int **c**) | **c**: character to be tested | 1 if there is match<br>0 if not | Check if given character is an alphabetic character or digit [a-zA-Z0-9] |
| **int** ft_isascii(int **c**) | **c**: character to be tested | 1 if there is match<br>0 if not | Check if given character is in range of standard ascii table |
| **int** ft_isprint(int **c**) | **c**: character to be tested | 1 if there is match<br>0 if not | Check if given character is a printable character |
| **int** ft_toupper(int **c**) | **c**: | | |
| **int** ft_tolower(int **c**) | **c**: | | |

### 2. String handling
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **size_t** ft_strlen(const char \***s**) | **s**: string to be checked | length of **s** | Calculates length of string **s** excluding terminating byte "\0" |
| **size_t** ft_strlcpy(char \***dst**, const char \***src**, size_t **size**) | **dst**: buffer to be copied to<br>**src**: NUL-terminated string to be copied from<br>**size**: size of the **dst** buffer | the size of string it tried to create (size of **src**) | Function copies up to **size** - 1 characters from **dst** NUL-terminating the result |
| **size_t** ft_strlcat(char \***dst**, const char \***src**, size_t **size**) | **dst**: buffer to be copied to<br>**src**: NUL-terminated string to be copied from<br>**size**: size of the **dst** buffer | the size of string it tried to create (sum of lengths of **dst** and **src**) | Append **src** to end of **dst** up to **size** - **dst** length - 1 NUL-terminating the resulting string, if lenght of **dst** is smaller than **size** then **dst** length is **size** and is not terminated |
| **char** \*ft_strchr(const char \***s**, int **c**) | **s**: string to be search<br>**c**: character to be search for | pointer to the first found character **c** in the string **s** | Searches string **s** for character **c** returning pointer to the first found character in the string **s** |
| **char** \*ft_strrchr(const char \***s**, int **c**) | **s**: string to be search<br>**c**: character to be search for | pointer to the last found character **c** in the string **s** | Searches string **s** for character **c** returning pointer to the last found character in the string **s** |
| **int** ft_strncmp(const char \***s1**, const char \***s2**, size_t **n**) | **s1** and **s2**: strings to compare <br>**n**: number of bytes to be compared | negative if **s1** < **s2**,<br>positive if **s1** > **s2** or<br>0 if **s1** == **s2** | Compares first **n** bytes of string |
| **char** \*ft_strnstr(const char \***big**, const char \***little**, size_t **len**) | **big**: string to be search<br> **little**: string to be looked for<br>**len**: how many characters to search | Pointer to first occurence of **little** in **big** or NULL otherwise | Searches at most **len** characters in **big** for **little** returning pointer if found or NULL if not |
| **char** \*ft_strdup(const char \***s**) | **s**: string to be cloned | Pointer to the clone of **s** or NULL if allocation failed | Clones stirng **s** to the new string and returns its pointer that can be freed with free |

### 3. Memory handling
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **void** \*ft_memset(void \***s**, int **c**, size_t **n**) | **s**: buffer of bytes<br>**c**: value to fill buffer with<br>**n**: number of bytes to fill | Pointer to **s** | Fill **n** bytes of buffer **s** with value **c**, **c** is cast to unsigned char |
| **void** ft_bzero(void \***s**, size_t **n**) | **s**: buffer of bytes<br>**n**: size of buffer | Poiner to **s** | Fills **n** bytes of buffer **s** with value 0 |
| **void** \*ft_memcpy(void \***dest**, const void \***src**, size_t **n**) | **dest**: buffer to be copied to<br>**src**: buffer to be copied from<br>**n**: number of bytes to copy | Pointer to **dest** | Copies **n** bytes from buffer **src** to buffer **dest**, buffers cannot overlap |
| **void** \*ft_memmove(void \***dest**, const void \***src**, size_t **n**) | **dest**: buffer to be copied to<br>**src**: buffer to be copied from<br>**n**: number of bytes to copy | Pointer to **dest** | Copies **n** bytes from buffer **src** to buffer **dest**, buffers can overlap |
| **void** \*ft_memchr(const void \***s**, int **c**, size_t **n**) | **s**: buffer to be searched<br>**c**: byte to find<br>**n**: size of **s** | Pointer to the first occurence of **c** or NULL if **c** is not found | Scans first **n** bytes if **s** for first instance of byte **c**. Both **c** and bytes of **s** is considered to be unsinged char |
| **int** ft_memcmp(const void \***s1**, const void \***s2**, size_t **n**) | **s1** and **s2**: buffer to compare against<br>**n**: number of bytes to compare | negative if **s1** < **s2**,<br>positive if **s1** > **s2** or<br>0 if **s1** == **s2** | Compares first **n** bytes of buffers **s1** and **s2**. **s1** and **s2** is considered to be unsigned char |
| **void** \*ft_calloc(size_t **n**, size_t **size**) | **n**: number of elements<br>**size**: size of element | Pointer to created memory arena or NULL if creation failed | Allocates **n** \* **size** space in memory, and set it to 0 |

### 4. Converter  
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **int** ft_atoi(const char \***nptr**) | **nptr**: string to convert to int | int | Converts initial portion of **nptr** to int |
</details>

<details>
	<summary>Extra functions</summary>

Additional functions not found in `libc` or found in different form
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **char** \*ft_substr(const char \***s**, unsigned int **start**, size_t **len**) | **s**: string to be copied from   <br>**start**: starting index of substring<br>**len**: maximum length of substring | Pointer to new string or NULL if allocation failed | Allocates new memory and returns substring created from **s** starting on index **start** and is at max length of **len**,  |
| **char** \*ft_strjoin(const char \***s1**, const char \***s2**) | **s1** and **s2**: strings to join | New string with content from both **s1** and **s2** or NULL if allocation fails | Allocates memory and returns new string created by appending **s2** to the end of **s1** |
| **char** \*ft_strtrim(const char \***s1**, const char \***set**) | **s1**: String to be trimmed <br>**set**: Set of characters to be removed | New string with **set** characters trimmed from start and end of **s1** or NULL if allocation fails | Allocates new memory for trimmed string **s1** with **set** characters removed from start and end of string |
| **char** \*\*ft_split(const char \***s**, char **c**) | **s**: string to be split<br>**c**: character used as delimiter | NULL ended list containing strings made by spliting **s** with delimiter **c** or NULL if allocation fails | Allocates memory and returns list of strings created by spliting **s** using character **c** as delimiter |
| **char** \*ft_itoa(int **n**) | **n**: integer to convert into string | String created from **n** or NULL if allocation fails | Allocates memory and converts integer **n** into its string representation |
| **char** \*ft_strmapi(const char \***s**, char (\***f**)(unsigned int, char)) | **s**: string to iterate over<br>**f**: function used on each element of string **s** | New string from using **f** on elements of **s** or NULL if allocation fails | Applies function **f** to each character of string **s**, with index number as first argument and character as second. New string is created to hold the results. |
| **void** ft_striteri(char \***s**, char (\***f**)(unsigned int, char*)) | **s**: string to iterate over<br>**f**: function used on each element of string **s** | | Applies function **f** to each character of string **s** with index as first argument and pointer to character as second | 
| **void** ft_putchar_fd(char **c**, int **fd**) | **c**: character to output<br>**fd**: the file descriptor on which to write | | Output character **c** to the specified file descriptor |
| **void** ft_putstr_fd(char \***s**, int **fd**) | **s**: string to output<br>**fd**: the file descriptor on which to write | | Output string **s** to the specified file descriptor |
| **void** ft_putendl_fd(char \***s**, int **fd**) | **s**: character to output<br>**fd**: the file descriptor on which to write | | Output string **s** to the specified file descriptor followed by new line |
| **void** ft_putnbr_fd(int **n**, int **fd**) | **n**: integer to output<br>**fd**: the file descriptor on which to write | | Output integer **n** to the specified file descriptor |

</details>

<details>
	<summary>Linked list</summary>

List structure looks like this
```
typedef struct s_list
{
    void            *content,
    struct s_list   *next
}                   t_list
```
where `content` is the data stored in the node, and `next` is next node in the list, or NULL if it's the last node on the list.

| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **t_list** \*ft_lstnew(void \***content**) | **content**: content to store in new node | Pointer to new node or NULL if allocation fails | Allocates new memory and set content of the node to **content**. Variable next set to 0 |
| **void** ft_lstadd_front(t_list \*\***lst**, t_list \***new**)| **lst**: address to the first node of the list<br>**new**: node to be added | | Adds node **new** to the start of list **lst** |
| **int** ft_lstsize(t_list \***lst**) | **lst**: address to the first node of the list | Calculated length of **lst** | Calculates and return the numbers of nodes in **lst** |
| **t_list** \*ft_lstlast(t_list \***lst**) | **lst**: address to the first node of the list | Pointer to the last element of the list **lst** | Returns last node in list **lst** |
| **void** ft_lstadd_back(t_list \*\***lst**, t_list \***new**) | **lst**: address to the first node of the list<br>**new**: node to be added | | Adds node **new** to the end of list **lst** |
| **void** ft_lstdelone(t_list \***lst**, void (\***del**)(void \*)) | **lst**: address to the node<br>**del**: function to delete content of node | | Delete node **lst** using **del** function to delete content and free node from memory |
| **void** ft_lstclear(t_list \*\***lst**, void (\***del**)(void \*)) | **lst**: address to the first node to be cleared<br>**del**: function to delete content of nodes | | Deletes and frees the node and all its successor using **del** function on content of nodes |
| **void** ft_lstiter(t_list \***lst**, void (\***f**)(void \*)) | **lst**: address to the first node of the list<br>**f**: address of function to apply on each node's content | | Iterates through list **lst** and applies the funtion **f** to the content of each node |
| **t_list** \*ft_lstmap(t_list \***lst**, void \*(\***f**)(void \*), void (\***del**)(void \*)) | **lst**: address to the first node of the list<br>**f**: address of function to apply on each node's content<br>**del**: address of function to delete node's content if needed | New list or NULL if allocation fails | Iterates through list **lst** and applies the function **f** to the content of each node. Output of each successfull application of function **f** is then used to create the new list. If |
</details>
</details>

# Instructions

### 1. Compiling
To build this library use  
```
make
```
command for basic compilation or
```
make re
```
to recompile all source files 

### 2. Cleaning
To delete all work files use
```
make clean
```
or
```
make fclean
```
to delete all work files and created library

### 3. Debugging
Compiling with debuging information enabled can be done using 
```
make debug
```
this will not recompile existing files older than already generated objects, to do that use
```
make redebug
```

### 4. Usage
To use this library you need to link it during compilation with `-L<path_to_library> -lft`

# Resources
- [Markdown Guide](https://www.markdownguide.org) for cheatsheet on how to use markdown syntax
- [Makefile Tutorial](https://makefiletutorial.com/) for tutoral on Makefiles
- [GNU website](https://www.gnu.org/software/make/) for documentation on Makefiles
> AI wasn't used to make this library

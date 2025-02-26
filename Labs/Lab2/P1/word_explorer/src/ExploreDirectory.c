#include "../include/ExploreDirectory.h"

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

#include "../include/ContainsWord.h"

/**
 * @brief Tries opening directory at dirpath and calls ContainsWord on all the
 * files that are regular (not directory or other). For each file the word is
 * found in, the filepath is printed to the user.
 *
 * @param dirpath Path to directory
 * @param word  Word to search for in files in dirpath
 */
void ExploreDirectory(const char *dirpath, const char *word) {
  DIR *dir = opendir(dirpath);
  if (!dir) {
    perror("Error opening directory");
    return;
  }

  struct dirent *entry;  // file information
  char filepath[1024];   // used to store full path of each file

  while ((entry = readdir(dir)) != NULL) {
    // Ignore "." and ".." entries
    if (entry->d_name[0] == '.') continue;

    snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);

    struct stat path_stat;
    stat(filepath, &path_stat);  // gets metadata of file

    if (S_ISREG(path_stat.st_mode)) {  // check if regular file (not directory
                                       // or other)
      if (ContainsWord(filepath, word)) {
        printf("Found in: %s\n", filepath);
      }
    }
  }

  closedir(dir);
}

// [INCLUDE]

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

// [SOLUTION START]

struct DomainBox {
  size_t domain_name;
  std::vector<size_t> local_names;
};

class Solution {
 public:
  int numUniqueEmails(std::vector<std::string>& emails) {
    std::vector<DomainBox> database;

    for (unsigned long i = 0; i < emails.size(); i++) {  // for each email
      std::string email = emails[i];
      unsigned long at_position = email.find('@');
      std::string domain_name = email.substr(at_position + 1);
      std::string local_name = email.substr(0, at_position);
      if (int(local_name.find('+')) != -1) {
        local_name.assign(local_name.substr(0, local_name.find('+')));
      }

      for (int l = int(local_name.length()) - 1; l >= 0;
           l--) {  // for each letter
        if (local_name[l] == '.') {
          local_name.erase(l, 1);
        }
      }

      printf("%s %s\n", local_name.c_str(), domain_name.c_str());

      auto local_name_hash = std::hash<std::string>{}(local_name);
      auto domain_name_hash = std::hash<std::string>{}(domain_name);

      bool already_has_domain = false;
      for (int k = 0; k < int(database.size()); k++) {
        if (domain_name_hash == database[k].domain_name) {
          already_has_domain = true;

          bool alread_has_local = false;
          for (int kk = 0; kk < int(database[k].local_names.size()); kk++) {
            if (local_name_hash == database[k].local_names[kk]) {
              alread_has_local = true;
              break;
            }
          }
          if (!alread_has_local) {
            database[k].local_names.push_back(local_name_hash);
          }

          break;
        }
      }
      if (!already_has_domain) {
        DomainBox domainBox = DomainBox();
        domainBox.domain_name = domain_name_hash;
        domainBox.local_names.push_back(local_name_hash);
        database.push_back(domainBox);
      }
    }

    int result = 0;
    for (int i = 0; i < int(database.size()); i++) {
      result += database[i].local_names.size();
    }
    return result;
  }
};

// [SOLUTION END]

// [MAIN]

int main() {
  printf("[TRACE] START\n");

  // [set input]
  std::vector<std::string> emails = {"tes..t.email+alex@leetcode.com",
                                     "test.e.mail+bob.cathy@leetcode.com",
                                     "testemail+david@lee.tcode.com"};
  // {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};

  // [call solution]
  int result = Solution().numUniqueEmails(emails);

  // [verify result]
  printf("result = %d\n", result);

  printf("[TRACE] END\n");
}

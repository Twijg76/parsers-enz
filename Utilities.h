
#include <cmath>

/**
 * @namespace Util
 * @brief Collects utility methods.
 */
namespace Util {

    /** Rounds a double to an integer correctly.
     *
     * @param d
     * @return
     */
    inline int round(double d) {
        return static_cast<int>(std::round(d));
    }


    /** Een methode om na te kijken of een string een getal is.
    * Deze implementatie kan verandert worden en kan dus beter los staan van
    * alle andere code
    * @return
    */
    static bool isNumber(const std::string&);

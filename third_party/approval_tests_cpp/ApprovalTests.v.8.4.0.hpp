// Approval Tests version v.8.4.0
// More information at: https://github.com/approvals/ApprovalTests.cpp

#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <utility>
#include <sys/stat.h>
#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <type_traits>
#include <memory>
#include <numeric>
#include <cstdlib>
#include <exception>
#include <map>
 // ******************** From: Reporter.h
#ifndef APPROVALTESTS_CPP_REPORTER_H
#define APPROVALTESTS_CPP_REPORTER_H


namespace ApprovalTests
{
    
    class Reporter
    {
    public:
        virtual ~Reporter() = default;
        virtual bool report(std::string received,
                            std::string approved) const = 0;
    };

    namespace Detail
    {
        
        template <typename T, typename R = void>
        using EnableIfNotDerivedFromReporter = typename std::enable_if<
            !std::is_base_of<Reporter, typename std::decay<T>::type>::value,
            R>::type;
    } 
}

#endif

 // ******************** From: QuietReporter.h
#ifndef APPROVALTESTS_CPP_QUIETREPORTER_H
#define APPROVALTESTS_CPP_QUIETREPORTER_H


namespace ApprovalTests
{
    
    class QuietReporter : public Reporter
    {
    public:
        bool report(std::string ,
                    std::string ) const override
        {
            return true;
        }
    };
}

#endif 

 // ******************** From: ApprovalTestsVersion.h
#ifndef APPROVALTESTS_CPP_APPROVALTESTSVERSION_H
#define APPROVALTESTS_CPP_APPROVALTESTSVERSION_H

#define APPROVALTESTS_VERSION_MAJOR 8
#define APPROVALTESTS_VERSION_MINOR 4
#define APPROVALTESTS_VERSION_PATCH 0
#define APPROVALTESTS_VERSION_STR "8.4.0"

#define APPROVALTESTS_VERSION                                                  \
    (APPROVALTESTS_VERSION_MAJOR * 10000 + APPROVALTESTS_VERSION_MINOR * 100 + \
     APPROVALTESTS_VERSION_PATCH)

#endif 

 // ******************** From: Blocker.h
#ifndef APPROVALTESTS_CPP_BLOCKER_H
#define APPROVALTESTS_CPP_BLOCKER_H




namespace ApprovalTests
{
    class Blocker
    {
    public:
        Blocker() = default;
        Blocker(const Blocker&) = default;
        Blocker(Blocker&&) = default;
        Blocker& operator=(const Blocker&) = default;
        Blocker& operator=(Blocker&&) = default;

        virtual ~Blocker() = default;

        virtual bool isBlockingOnThisMachine() const = 0;
    };
}

#endif 

 // ******************** From: StringUtils.h


#ifndef APPROVALTESTS_CPP_STRINGUTILS_H
#define APPROVALTESTS_CPP_STRINGUTILS_H


namespace ApprovalTests
{
    class StringUtils
    {
    public:
        static std::string replaceAll(std::string inText,
                                      const std::string& find,
                                      const std::string& replaceWith)
        {
            size_t start_pos = 0;
            while ((start_pos = inText.find(find, start_pos)) !=
                   std::string::npos)
            {
                inText.replace(start_pos, find.length(), replaceWith);
                start_pos +=
                    replaceWith
                        .length(); 
            }
            return inText;
        }

        static bool contains(const std::string& inText, const std::string& find)
        {
            return inText.find(find, 0) != std::string::npos;
        }

        static std::string toLower(std::string inText)
        {
            std::string copy(inText);
            std::transform(
                inText.begin(), inText.end(), copy.begin(), [](char c) {
                    return static_cast<char>(tolower(c));
                });
            return copy;
        }

        static bool endsWith(std::string value, std::string ending)
        {
            if (ending.size() > value.size())
            {
                return false;
            }
            return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
        }

        template <typename T> static std::string toString(const T& contents)
        {
            std::stringstream s;
            s << contents;
            return s.str();
        }
    };
}
#endif 

 // ******************** From: Macros.h
#ifndef APPROVALTESTS_CPP_MACROS_H
#define APPROVALTESTS_CPP_MACROS_H




#define APPROVAL_TESTS_UNUSED(expr)                                            \
    do                                                                         \
    {                                                                          \
        (void)(expr);                                                          \
    } while (0)

#if __cplusplus >= 201703L
#define APPROVAL_TESTS_NO_DISCARD [[nodiscard]]
#else
#define APPROVAL_TESTS_NO_DISCARD
#endif

#endif 

 // ******************** From: WinMinGWUtils.h
#ifndef APPROVALTESTS_CPP_WINMINGWUTILS_H
#define APPROVALTESTS_CPP_WINMINGWUTILS_H

// <SingleHpp unalterable>

#if (defined(__MINGW32__) || defined(__MINGW64__))
#define APPROVAL_TESTS_MINGW
#endif

#ifdef APPROVAL_TESTS_MINGW
#ifdef __cplusplus
extern "C"
{
#endif

#include <sec_api/stdlib_s.h> /* errno_t, size_t */

    errno_t getenv_s(size_t* ret_required_buf_size,
                     char* buf,
                     size_t buf_size_in_bytes,
                     const char* name);

#ifdef __cplusplus
}
#endif

#endif // APPROVAL_TESTS_MINGW

// </SingleHpp>

#endif 

 // ******************** From: ApprovalWriter.h
#ifndef APPROVALTESTS_CPP_APPROVALWRITER_H
#define APPROVALTESTS_CPP_APPROVALWRITER_H

namespace ApprovalTests
{
    class ApprovalWriter
    {
    public:
        virtual ~ApprovalWriter() = default;
        virtual std::string getFileExtensionWithDot() const = 0;
        virtual void write(std::string path) const = 0;
        virtual void cleanUpReceived(std::string receivedPath) const = 0;
    };
}

#endif 

 // ******************** From: StringWriter.h
#ifndef APPROVALTESTS_CPP_STRINGWRITER_H
#define APPROVALTESTS_CPP_STRINGWRITER_H


namespace ApprovalTests
{
    class StringWriter : public ApprovalWriter
    {
    private:
        std::string s;
        std::string ext;

    public:
        explicit StringWriter(std::string contents,
                              std::string fileExtensionWithDot = ".txt")
            : s(std::move(contents)), ext(std::move(fileExtensionWithDot))
        {
        }

        std::string getFileExtensionWithDot() const override
        {
            return ext;
        }

        void write(std::string path) const override
        {
            std::ofstream out(path.c_str(), std::ofstream::out);
            if (!out)
            {
                throw std::runtime_error("Unable to write file: " + path);
            }
            this->Write(out);
            out.close();
        }

        void Write(std::ostream& out) const
        {
            out << s << "\n";
        }

        virtual void cleanUpReceived(std::string receivedPath) const override
        {
            remove(receivedPath.c_str());
        }
    };
}
#endif

 // ******************** From: FileUtils.h




#ifndef APPROVALTESTS_CPP_FILEUTILS_H
#define APPROVALTESTS_CPP_FILEUTILS_H


namespace ApprovalTests
{
    class FileUtils
    {
    public:
        static bool fileExists(const std::string& path)
        {
            struct stat info
            {
            };
            return stat(path.c_str(), &info) == 0;
        }

        static int fileSize(const std::string& path)
        {
            struct stat statbuf
            {
            };
            int stat_ok = stat(path.c_str(), &statbuf);

            if (stat_ok == -1)
            {
                return -1;
            }

            return int(statbuf.st_size);
        }

        static void ensureFileExists(const std::string& fullFilePath)
        {
            if (!fileExists(fullFilePath))
            {
                StringWriter s("", "");
                s.write(fullFilePath);
            }
        }

        static std::string getExtensionWithDot(const std::string& filePath)
        {
            std::size_t found = filePath.find_last_of('.');
            return filePath.substr(found);
        }

        static std::string readFileThrowIfMissing(const std::string& fileName)
        {
            std::ifstream in(fileName.c_str(), std::ios_base::in);
            if (!in)
            {
                throw std::runtime_error("File does not exist: " + fileName);
            }
            std::stringstream written;
            written << in.rdbuf();
            in.close();

            std::string text = written.str();
            return text;
        }

        static std::string
        readFileReturnEmptyIfMissing(const std::string& fileName)
        {
            if (FileUtils::fileExists(fileName))
            {
                return readFileThrowIfMissing(fileName);
            }
            else
            {
                return std::string();
            }
        }

        static void writeToFile(const std::string& filePath,
                                const std::string& content)
        {
            std::ofstream out(filePath.c_str(),
                              std::ios::binary | std::ofstream::out);
            if (!out)
            {
                throw std::runtime_error("Unable to write file: " + filePath);
            }
            out << content;
        }
    };
}

#endif 

 // ******************** From: SystemUtils.h
#ifndef APPROVALTESTS_CPP_SYSTEMUTILS_H
#define APPROVALTESTS_CPP_SYSTEMUTILS_H

// <SingleHpp unalterable>
#ifdef _WIN32
// ReSharper disable once CppUnusedIncludeDirective
#include <io.h>
#include <direct.h>
#else
// ReSharper disable once CppUnusedIncludeDirective
#include <unistd.h>
#endif
// </SingleHpp>



namespace ApprovalTests
{
    class SystemUtils
    {
    public:
        static bool isWindowsOs()
        {
#ifdef _WIN32
            return true;
#else
            return false;
#endif
        }

        static bool isCygwin()
        {
#ifdef __CYGWIN__
            return true;
#else
            return false;
#endif
        }

        static bool isMacOs()
        {
#ifdef __APPLE__
            return true;
#else
            return false;
#endif
        }

        static std::string getDirectorySeparator()
        {
            return isWindowsOs() ? "\\" : "/";
        }

        
        static std::string checkFilenameCase(const std::string& fullPath)
        {
            if (!isWindowsOs() || !FileUtils::fileExists(fullPath))
            {
                return fullPath;
            }
#ifdef _WIN32

            _finddata_t findFileData;
            auto hFind = _findfirst(fullPath.c_str(), &findFileData);

            if (hFind != -1)
            {
                const std::string fixedFilename = findFileData.name;
                const std::string fixedPath =
                    StringUtils::replaceAll(fullPath,
                                            StringUtils::toLower(fixedFilename),
                                            fixedFilename);
                _findclose(hFind);
                return fixedPath;
            }

#endif
            return fullPath;
        }

        static std::string safeGetEnvForWindows(char const* name)
        {
            APPROVAL_TESTS_UNUSED(name);
#ifdef _WIN32
            
            
            

            size_t size;
            getenv_s(&size, nullptr, 0, name);

            if (size != 0)
            {
                std::string result;
                result.resize(size);
                getenv_s(&size, &*result.begin(), size, name);
                result.pop_back();
                return result;
            }
#endif
            return std::string();
        }

        static std::string safeGetEnvForNonWindows(char const* name)
        {
            APPROVAL_TESTS_UNUSED(name);
            char* p = nullptr;
#ifndef _WIN32
            p = getenv(name);
#endif
            return (p != nullptr) ? p : std::string();
        }

        
        static std::string safeGetEnv(char const* name)
        {
            return isWindowsOs() ? safeGetEnvForWindows(name)
                                 : safeGetEnvForNonWindows(name);
        }

        static std::string getMachineName()
        {
            auto name = safeGetEnv("COMPUTERNAME");
            if (!name.empty())
            {
                return name;
            }

            name = safeGetEnv("HOSTNAME");
            if (!name.empty())
            {
                return name;
            }

            return "Unknown Computer";
        }

        static void makeDirectoryForWindows(const std::string& directory)
        {
            APPROVAL_TESTS_UNUSED(directory);
#ifdef _WIN32
            int nError = _mkdir(directory.c_str());
            if (nError != 0)
            {
                std::string helpMessage =
                    std::string("Unable to create directory: ") + directory;
                throw std::runtime_error(helpMessage);
            }
#endif
        }

        static void makeDirectoryForNonWindows(const std::string& directory)
        {
            APPROVAL_TESTS_UNUSED(directory);
#ifndef _WIN32
            mode_t nMode = 0733; 
            int nError = mkdir(directory.c_str(), nMode);
            if (nError != 0)
            {
                std::string helpMessage =
                    std::string("Unable to create directory: ") + directory;
                throw std::runtime_error(helpMessage);
            }
#endif
        }

        static void makeDirectory(const std::string& directory)
        {
            makeDirectoryForWindows(directory);
            makeDirectoryForNonWindows(directory);
        }

        static void ensureDirectoryExists(const std::string& fullFilePath)
        {
            if (!FileUtils::fileExists(fullFilePath))
            {
                makeDirectory(fullFilePath);
            }
        }

        static void runSystemCommandOrThrow(const std::string& command)
        {
            int exitCode = system(command.c_str());

            if (exitCode != 0)
            {
                throw std::runtime_error(command + ": failed with exit code " +
                                         std::to_string(exitCode));
            }
        }
    };
}
#endif

 // ******************** From: MachineBlocker.h
#ifndef APPROVALTESTS_CPP_MACHINEBLOCKER_H
#define APPROVALTESTS_CPP_MACHINEBLOCKER_H


namespace ApprovalTests
{
    class MachineBlocker : public Blocker
    {
    private:
        std::string machineName;
        bool block;

        MachineBlocker() = delete;

    public:
        MachineBlocker(std::string machineName, bool block)
            : machineName(std::move(machineName)), block(block)
        {
        }

        static MachineBlocker onMachineNamed(const std::string& machineName)
        {
            return MachineBlocker(machineName, true);
        }

        static MachineBlocker onMachinesNotNamed(const std::string& machineName)
        {
            return MachineBlocker(machineName, false);
        }

        virtual bool isBlockingOnThisMachine() const override
        {
            const auto isMachine =
                (SystemUtils::getMachineName() == machineName);
            return isMachine == block;
        }
    };
}

#endif 

 // ******************** From: FileUtilsSystemSpecific.h
#ifndef APPROVALTESTS_CPP_FILEUTILSSYSTEMSPECIFIC_H
#define APPROVALTESTS_CPP_FILEUTILSSYSTEMSPECIFIC_H


namespace ApprovalTests
{
    class FileUtilsSystemSpecific
    {
    public:
        static std::string getCommandLineForCopy(const std::string& source,
                                                 const std::string& destination,
                                                 bool isWindows)
        {
            if (isWindows)
            {
                return std::string("copy /Y ") + "\"" + source + "\" \"" +
                       destination + "\"";
            }
            else
            {
                return std::string("cp ") + "\"" + source + "\" \"" +
                       destination + "\"";
            }
        }

        static void copyFile(const std::string& source,
                             const std::string& destination)
        {
            auto cmd = getCommandLineForCopy(
                source, destination, SystemUtils::isWindowsOs());
            SystemUtils::runSystemCommandOrThrow(cmd);
        }
    };
}
#endif

 // ******************** From: AutoApproveReporter.h
#ifndef APPROVALTESTS_CPP_AUTOAPPROVEREPORTER_H
#define APPROVALTESTS_CPP_AUTOAPPROVEREPORTER_H



namespace ApprovalTests
{
    class AutoApproveReporter : public Reporter
    {
    public:
        bool report(std::string received, std::string approved) const override
        {
            std::cout << "file " << approved
                      << " automatically approved - next run should succeed\n";
            FileUtilsSystemSpecific::copyFile(received, approved);
            return true;
        }
    };
}

#endif

 // ******************** From: HelpMessages.h
#ifndef APPROVALTESTS_CPP_HELPMESSAGES_H
#define APPROVALTESTS_CPP_HELPMESSAGES_H


// <SingleHpp unalterable>
namespace ApprovalTests
{
    class HelpMessages
    {
    public:
        static std::string
        getMisconfiguredBuildHelp(const std::string& fileName)
        {
            std::string helpMessage = R"(* Welcome to Approval Tests.
*
* There seems to be a problem with your build configuration.
* We cannot find the test source file at:
*   [fileName]
*
* For details on how to fix this, please visit:
* https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TroubleshootingMisconfiguredBuild.md
)";
            return StringUtils::replaceAll(
                topAndTailHelpMessage(helpMessage), "[fileName]", fileName);
        }

        static std::string getMisconfiguredMainHelp()
        {
            std::string helpMessage = R"(* Welcome to Approval Tests.
*
* You have forgotten to configure your test framework for Approval Tests.
*
* To do this in Catch, add the following to your main.cpp:
*
*     #define APPROVALS_CATCH
*     #include "ApprovalTests.hpp"
*
* To do this in Google Test, add the following to your main.cpp:
*
*     #define APPROVALS_GOOGLETEST
*     #include "ApprovalTests.hpp"
*
* To do this in doctest, add the following to your main.cpp:
*
*     #define APPROVALS_DOCTEST
*     #include "ApprovalTests.hpp"
*
* To do this in [Boost].UT, add the following to your main.cpp:
*
*     #define APPROVALS_UT
*     #include "ApprovalTests.hpp"
*
* For more information, please visit:
* https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TroubleshootingMisconfiguredMain.md
)";
            return topAndTailHelpMessage(helpMessage);
        }

        static std::string topAndTailHelpMessage(const std::string& message)
        {
            const std::string lineBreak =
                "**************************************************************"
                "***************";
            const std::string lineBuffer =
                "*                                                             "
                "              *n";
            return lineBreak + 'n' + lineBuffer + message + lineBuffer +
                   lineBreak;
        }
    };
}
// </SingleHpp>

#endif 

 // ******************** From: ApprovalNamer.h
#ifndef APPROVALTESTS_CPP_APPROVALNAMER_H
#define APPROVALTESTS_CPP_APPROVALNAMER_H


namespace ApprovalTests
{
    class ApprovalNamer
    {
    public:
        virtual ~ApprovalNamer() = default;
        virtual std::string
        getApprovedFile(std::string extensionWithDot) const = 0;
        virtual std::string
        getReceivedFile(std::string extensionWithDot) const = 0;
    };
}

#endif

 // ******************** From: ApprovalTestNamer.h
#ifndef APPROVALTESTS_CPP_APPROVALTESTNAMER_H
#define APPROVALTESTS_CPP_APPROVALTESTNAMER_H


namespace ApprovalTests
{
    class TestName
    {
    public:
        const std::string& getFileName() const
        {
            checkBuildConfiguration(fileName);
            return fileName;
        }

        void setFileName(const std::string& file)
        {
            fileName = SystemUtils::checkFilenameCase(file);
        }

    private:
        static void checkBuildConfiguration(const std::string& fileName)
        {
            if (!FileUtils::fileExists(fileName))
            {
                throw std::runtime_error(getMisconfiguredBuildHelp(fileName));
            }
        }

    public:
        static std::string
        getMisconfiguredBuildHelp(const std::string& fileName)
        {
            return "\n\n" + HelpMessages::getMisconfiguredBuildHelp(fileName) +
                   "\n\n";
        }

        std::vector<std::string> sections;

    private:
        std::string fileName;
    };

    class TestConfiguration
    {
    public:
        std::string subdirectory;
    };

    class ApprovalTestNamer : public ApprovalNamer
    {
    private:
    public:
        ApprovalTestNamer() = default;

        std::string getTestName() const
        {
            std::stringstream ext;
            auto test = getCurrentTest();
            for (size_t i = 0; i < test.sections.size(); i++)
            {
                if (0 < i)
                {
                    ext << ".";
                }
                ext << test.sections[i];
            }

            return convertToFileName(ext.str());
        }

        static bool isForbidden(char c)
        {
            static std::string forbiddenChars("\\/:?\"<>|' ");
            return std::string::npos != forbiddenChars.find(c);
        }

        static std::string convertToFileName(const std::string& fileName)
        {
            std::stringstream result;
            for (auto ch : fileName)
            {
                if (!isForbidden(ch))
                {
                    result << ch;
                }
                else
                {
                    result << "_";
                }
            }
            return result.str();
        }

        static TestName& getCurrentTest()
        {
            try
            {
                return currentTest();
            }
            catch (const std::runtime_error&)
            {
                std::string helpMessage = getMisconfiguredMainHelp();
                throw std::runtime_error(helpMessage);
            }
        }

        static std::string getMisconfiguredMainHelp()
        {
            return "\n\n" + HelpMessages::getMisconfiguredMainHelp() + "\n\n";
        }

        
        std::string getFileName() const
        {
            return getSourceFileName();
        }

        std::string getSourceFileName() const
        {
            auto file = getCurrentTest().getFileName();
            auto start = file.rfind(SystemUtils::getDirectorySeparator()) + 1;
            auto end = file.rfind('.');
            auto fileName = file.substr(start, end - start);
            return convertToFileName(fileName);
        }

        std::string getDirectory() const
        {
            auto file = getCurrentTest().getFileName();
            auto end = file.rfind(SystemUtils::getDirectorySeparator()) + 1;
            auto directory = file.substr(0, end);
            if (!testConfiguration().subdirectory.empty())
            {
                directory += testConfiguration().subdirectory +
                             SystemUtils::getDirectorySeparator();
                SystemUtils::ensureDirectoryExists(directory);
            }
            return directory;
        }

        static TestName& currentTest(TestName* value = nullptr)
        {
            static TestName* staticValue;
            if (value != nullptr)
            {
                staticValue = value;
            }
            if (staticValue == nullptr)
            {
                throw std::runtime_error(
                    "The variable in currentTest() is not initialised");
            }
            return *staticValue;
        }

        static TestConfiguration& testConfiguration()
        {
            static TestConfiguration configuration;
            return configuration;
        }

        virtual std::string
        getApprovedFile(std::string extensionWithDot) const override
        {

            return getFullFileName(".approved", extensionWithDot);
        }

        virtual std::string
        getReceivedFile(std::string extensionWithDot) const override
        {

            return getFullFileName(".received", extensionWithDot);
        }

        std::string getOutputFileBaseName() const
        {
            return getSourceFileName() + "." + getTestName();
        }

        std::string getFullFileName(const std::string& approved,
                                    const std::string& extensionWithDot) const
        {
            std::stringstream ext;
            ext << getDirectory() << getOutputFileBaseName() << approved
                << extensionWithDot;
            return ext.str();
        }
    };
}

#endif

 // ******************** From: SectionNameDisposer.h
#ifndef APPROVALTESTS_CPP_SECTIONNAMEDISPOSER_H
#define APPROVALTESTS_CPP_SECTIONNAMEDISPOSER_H


namespace ApprovalTests
{
    class APPROVAL_TESTS_NO_DISCARD SectionNameDisposer
    {
    public:
        SectionNameDisposer(TestName& currentTest,
                            const std::string& scope_name)
            : currentTest(currentTest)
        {
            
            
            currentTest.sections.push_back(scope_name);
        }

        ~SectionNameDisposer()
        {
            
            currentTest.sections.pop_back();
        }

    private:
        TestName& currentTest;
    };
}

#endif 

 // ******************** From: GoogleCustomizationsFactory.h
#ifndef APPROVALTESTS_CPP_GOOGLECUSTOMIZATIONSFACTORY_H
#define APPROVALTESTS_CPP_GOOGLECUSTOMIZATIONSFACTORY_H



namespace ApprovalTests
{
    class GoogleCustomizationsFactory
    {
    public:
        using Comparator =
            std::function<bool(const std::string&, const std::string&)>;

    private:
        using ComparatorContainer = std::vector<Comparator>;
        static ComparatorContainer& comparatorContainer()
        {
            static ComparatorContainer container;
            if (container.empty())
            {
                auto exactNameMatching =
                    [](const std::string& testFileNameWithExtension,
                       const std::string& testCaseName) {
                        return StringUtils::contains(testFileNameWithExtension,
                                                     testCaseName + ".");
                    };
                container.push_back(exactNameMatching);
            }
            return container;
        }

    public:
        static ComparatorContainer getEquivalencyChecks()
        {
            return comparatorContainer();
        }

        APPROVAL_TESTS_NO_DISCARD static bool
        addTestCaseNameRedundancyCheck(const Comparator& comparator)
        {
            comparatorContainer().push_back(comparator);
            return true;
        }
    };
}

#endif 

 // ******************** From: CartesianProduct.h
#ifndef APPROVALTESTS_CPP_CARTESIANPRODUCT_H
#define APPROVALTESTS_CPP_CARTESIANPRODUCT_H


namespace ApprovalTests
{
    namespace CartesianProduct
    {
        namespace Detail
        {

            
            
            template <bool B, class T = void>
            using enable_if_t = typename std::enable_if<B, T>::type;

            
            template <std::size_t... Is> struct index_sequence
            {
            };

            template <std::size_t N, std::size_t... Is>
            struct make_index_sequence
                : make_index_sequence<N - 1, N - 1, Is...>
            {
            };

            template <std::size_t... Is>
            struct make_index_sequence<0, Is...> : index_sequence<Is...>
            {
            };
            

            
            
            template <class Tuple> constexpr std::size_t tuple_size()
            {
                return std::tuple_size<
                    typename std::remove_reference<Tuple>::type>::value;
            }

            template <class Tuple>
            using make_tuple_idxs = make_index_sequence<tuple_size<Tuple>()>;

            
            
            template <class F, class Tuple, std::size_t... I>
            constexpr auto apply_impl(F&& f, Tuple&& t, index_sequence<I...>)
                -> decltype(
                    std::forward<F>(f)(std::get<I>(std::forward<Tuple>(t))...))
            {
                return std::forward<F>(f)(
                    std::get<I>(std::forward<Tuple>(t))...);
            }

            template <class F, class Tuple>
            auto apply(F&& f, Tuple&& t)
                -> decltype(apply_impl(std::forward<F>(f),
                                       std::forward<Tuple>(t),
                                       make_tuple_idxs<Tuple>{}))
            {
                return apply_impl(std::forward<F>(f),
                                  std::forward<Tuple>(t),
                                  make_tuple_idxs<Tuple>{});
            }
            

            template <class Tuple, class F, std::size_t... Is>
            void for_each_impl(Tuple&& t, F&& f, index_sequence<Is...>)
            {
                (void)std::initializer_list<int>{
                    (std::forward<F>(f)(std::get<Is>(std::forward<Tuple>(t))),
                     0)...};
            }

            template <class Tuple, class F> void for_each(Tuple&& t, F&& f)
            {
                for_each_impl(std::forward<Tuple>(t),
                              std::forward<F>(f),
                              make_tuple_idxs<Tuple>{});
            }

            template <class Tuple, class F, std::size_t... Is>
            auto transform_impl(Tuple&& t, F&& f, index_sequence<Is...>)
                -> decltype(std::make_tuple(std::forward<F>(f)(
                    std::get<Is>(std::forward<Tuple>(t)))...))
            {
                return std::make_tuple(std::forward<F>(f)(
                    std::get<Is>(std::forward<Tuple>(t)))...);
            }

            template <class F, class Tuple>
            auto transform(Tuple&& t, F&& f = {})
                -> decltype(transform_impl(std::forward<Tuple>(t),
                                           std::forward<F>(f),
                                           make_tuple_idxs<Tuple>{}))
            {
                return transform_impl(std::forward<Tuple>(t),
                                      std::forward<F>(f),
                                      make_tuple_idxs<Tuple>{});
            }

            template <class Predicate> struct find_if_body
            {
                const Predicate& pred;
                std::size_t& index;
                std::size_t currentIndex = 0;
                bool found = false;

                find_if_body(const Predicate& p, std::size_t& i)
                    : pred(p), index(i)
                {
                }

                template <typename T> void operator()(T&& value)
                {
                    if (found)
                        return;
                    if (pred(std::forward<T>(value)))
                    {
                        index = currentIndex;
                        found = true;
                    }
                    ++currentIndex;
                }
            };

            template <class Predicate, class Tuple>
            std::size_t find_if(Tuple&& tuple, Predicate pred = {})
            {
                std::size_t idx = tuple_size<Tuple>();
                for_each(std::forward<Tuple>(tuple),
                         find_if_body<Predicate>(pred, idx));
                return idx;
            }

            template <class Predicate, class Tuple>
            bool any_of(Tuple&& tuple, Predicate pred = {})
            {
                return find_if(std::forward<Tuple>(tuple), pred) !=
                       tuple_size<Tuple>();
            }

            struct is_range_empty
            {
                template <class T> bool operator()(const T& range) const
                {
                    using std::begin;
                    using std::end;
                    return begin(range) == end(range);
                }
            };

            
            struct dereference_iterator
            {
                template <class It>
                auto operator()(It&& it) const
                    -> decltype(*std::forward<It>(it))
                {
                    return *std::forward<It>(it);
                }
            };

            
            template <class Its, std::size_t I = tuple_size<Its>() - 1>
            enable_if_t<I == 0>
            increment_iterator(Its& it, const Its&, const Its&)
            {
                ++std::get<I>(it);
            }

            
            template <class Its, std::size_t I = tuple_size<Its>() - 1>
            enable_if_t<I != 0>
            increment_iterator(Its& its, const Its& begins, const Its& ends)
            {
                if (++std::get<I>(its) == std::get<I>(ends))
                {
                    std::get<I>(its) = std::get<I>(begins);
                    increment_iterator<Its, I - 1>(its, begins, ends);
                }
            }
        } 

        
        
        
        
        template <class F, class... Ranges>
        void cartesian_product(F&& f, const Ranges&... ranges)
        {
            using std::begin;
            using std::end;

            if (Detail::any_of<Detail::is_range_empty>(
                    std::forward_as_tuple(ranges...)))
                return;

            const auto begins = std::make_tuple(begin(ranges)...);
            const auto ends = std::make_tuple(end(ranges)...);

            for (auto its = begins; std::get<0>(its) != std::get<0>(ends);
                 Detail::increment_iterator(its, begins, ends))
            {
                
                
                
                
                Detail::apply(
                    std::forward<F>(f),
                    Detail::transform<Detail::dereference_iterator>(its));
            }
        }
    } 
} 

#endif

 // ******************** From: ExistingFile.h
#ifndef APPROVALTESTS_CPP_EXISTINGFILE_H
#define APPROVALTESTS_CPP_EXISTINGFILE_H


namespace ApprovalTests
{
    class ExistingFile : public ApprovalWriter
    {
        std::string filePath;

    public:
        explicit ExistingFile(std::string filePath)
            : filePath(std::move(filePath))
        {
        }
        virtual std::string getFileExtensionWithDot() const override
        {
            return FileUtils::getExtensionWithDot(filePath);
        }
        virtual void write(std::string ) const override
        {
            
        }
        virtual void
            cleanUpReceived(std::string ) const override
        {
            
        }
    };
}

#endif

 // ******************** From: ConvertForCygwin.h
#ifndef APPROVALTESTS_CPP_CONVERTFORCYGWIN_H
#define APPROVALTESTS_CPP_CONVERTFORCYGWIN_H


namespace ApprovalTests
{
    class ConvertForCygwin
    {
    public:
        virtual ~ConvertForCygwin() = default;

        virtual std::string convertProgramForCygwin(const std::string& filePath)
        {
            return "$(cygpath '" + filePath + "')";
        }

        virtual std::string
        convertFileArgumentForCygwin(const std::string& filePath)
        {
            return "$(cygpath -aw '" + filePath + "')";
        }
    };

    class DoNothing : public ConvertForCygwin
    {
    public:
        std::string
        convertProgramForCygwin(const std::string& filePath) override
        {
            return filePath;
        }

        std::string
        convertFileArgumentForCygwin(const std::string& filePath) override
        {
            return filePath;
        }
    };
}

#endif 

 // ******************** From: DiffInfo.h
#ifndef APPROVALTESTS_CPP_DIFFINFO_H
#define APPROVALTESTS_CPP_DIFFINFO_H


namespace ApprovalTests
{
    enum class Type
    {
        TEXT,
        IMAGE,
        TEXT_AND_IMAGE
    };

    struct DiffInfo
    {
        static std::string receivedFileTemplate()
        {
            return "{Received}";
        }

        static std::string approvedFileTemplate()
        {
            return "{Approved}";
        }

        static std::string programFileTemplate()
        {
            return "{ProgramFiles}";
        }

        static std::string getDefaultArguments()
        {
            return receivedFileTemplate() + ' ' + approvedFileTemplate();
        }

        DiffInfo(std::string program, Type type)
            : program(std::move(program))
            , arguments(getDefaultArguments())
            , type(type)
        {
        }
        DiffInfo(std::string program, std::string arguments, Type type)
            : program(std::move(program))
            , arguments(std::move(arguments))
            , type(type)
        {
        }
        std::string program;
        std::string arguments;
        Type type;

        static std::vector<std::string> getProgramFileLocations()
        {
            std::vector<std::string> possibleWindowsPaths;
            const std::vector<const char*> envVars = {
                "ProgramFiles", "ProgramW6432", "ProgramFiles(x86)"};

            for (const auto& envVar : envVars)
            {
                std::string envVarValue = SystemUtils::safeGetEnv(envVar);
                if (!envVarValue.empty())
                {
                    envVarValue += '\\';
                    possibleWindowsPaths.push_back(envVarValue);
                }
            }
            return possibleWindowsPaths;
        }

        std::string getProgramForOs() const
        {
            std::string result = program;
            std::vector<std::string> possibleWindowsPaths =
                getProgramFileLocations();

            if (result.rfind(programFileTemplate(), 0) == 0)
            {
                for (const auto& path : possibleWindowsPaths)
                {
                    auto result1 = StringUtils::replaceAll(
                        result, programFileTemplate(), path);
                    if (FileUtils::fileExists(result1))
                    {
                        return result1;
                    }
                }
            }
            return result;
        }
    };
}

#endif 

 // ******************** From: CommandLauncher.h
#ifndef APPROVALTESTS_CPP_COMMANDLAUNCHER_H
#define APPROVALTESTS_CPP_COMMANDLAUNCHER_H


namespace ApprovalTests
{
    
    class CommandLauncher
    {
    public:
        virtual ~CommandLauncher() = default;
        virtual bool launch(const std::string& commandLine) = 0;
        virtual std::string
        getCommandLine(const std::string& commandLine) const = 0;
    };
}

#endif

 // ******************** From: CommandReporter.h
#ifndef APPROVALTESTS_CPP_COMMANDREPORTER_H
#define APPROVALTESTS_CPP_COMMANDREPORTER_H


namespace ApprovalTests
{
    
    class CommandReporter : public Reporter
    {
    private:
        std::string cmd;
        std::string arguments = DiffInfo::getDefaultArguments();
        CommandLauncher* l;
        std::shared_ptr<ConvertForCygwin> converter;

        std::string assembleFullCommand(const std::string& received,
                                        const std::string& approved) const
        {
            auto convertedCommand =
                '"' + converter->convertProgramForCygwin(cmd) + '"';
            auto convertedReceived =
                '"' + converter->convertFileArgumentForCygwin(received) + '"';
            auto convertedApproved =
                '"' + converter->convertFileArgumentForCygwin(approved) + '"';

            std::string args;
            args = StringUtils::replaceAll(
                arguments, DiffInfo::receivedFileTemplate(), convertedReceived);
            args = StringUtils::replaceAll(
                args, DiffInfo::approvedFileTemplate(), convertedApproved);

            return convertedCommand + ' ' + args;
        }

    protected:
        CommandReporter(std::string command, CommandLauncher* launcher)
            : cmd(std::move(command)), l(launcher)
        {
            checkForCygwin();
        }

        CommandReporter(std::string command,
                        std::string args,
                        CommandLauncher* launcher)
            : cmd(std::move(command)), arguments(std::move(args)), l(launcher)
        {
            checkForCygwin();
        }

    public:
        static bool exists(const std::string& command)
        {
            bool foundByWhich = false;
            if (!SystemUtils::isWindowsOs())
            {
                std::string which = "which " + command + " > /dev/null 2>&1";
                int result = system(which.c_str());
                foundByWhich = (result == 0);
            }
            return foundByWhich || FileUtils::fileExists(command);
        }

        bool report(std::string received, std::string approved) const override
        {
            if (!exists(cmd))
            {
                return false;
            }
            FileUtils::ensureFileExists(approved);
            return l->launch(assembleFullCommand(received, approved));
        }

        std::string getCommandLine(const std::string& received,
                                   const std::string& approved) const
        {
            return l->getCommandLine(assembleFullCommand(received, approved));
        }

    public:
        void checkForCygwin()
        {
            useCygwinConversions(SystemUtils::isCygwin());
        }

        
        void useCygwinConversions(bool useCygwin)
        {
            if (useCygwin)
            {
                converter = std::make_shared<ConvertForCygwin>();
            }
            else
            {
                converter = std::make_shared<DoNothing>();
            }
        }
    };
}
#endif 

 // ******************** From: SystemLauncher.h

#ifndef APPROVALTESTS_CPP_SYSTEMLAUNCHER_H
#define APPROVALTESTS_CPP_SYSTEMLAUNCHER_H


namespace ApprovalTests
{
    class SystemLauncher : public CommandLauncher
    {
    private:
        bool useWindows_ = SystemUtils::isWindowsOs();
        bool isForeground_ = false;

    public:
        explicit SystemLauncher(bool isForeground = false)
            : isForeground_(isForeground)
        {
        }

        bool launch(const std::string& commandLine) override
        {
            std::string launch = getCommandLine(commandLine);

            SystemUtils::runSystemCommandOrThrow(launch);
            return true;
        }

        
        void invokeForWindows(bool useWindows)
        {
            useWindows_ = useWindows;
        }

        void setForeground(bool foreground)
        {
            isForeground_ = foreground;
        }

        bool isForeground() const
        {
            return isForeground_;
        }

        std::string
        getCommandLine(const std::string& commandLine) const override
        {
            std::string launch =
                useWindows_ ? getWindowsCommandLine(commandLine, isForeground_)
                            : getUnixCommandLine(commandLine, isForeground_);
            return launch;
        }

        std::string getWindowsCommandLine(const std::string& commandLine,
                                          bool foreground) const
        {
            std::string launch =
                foreground
                    ? (std::string("cmd /S /C ") + "\"" + commandLine + "\"")
                    : ("start \"\" " + commandLine);

            return launch;
        }

        std::string getUnixCommandLine(const std::string& commandLine,
                                       bool foreground) const
        {
            std::string launch =
                foreground ? commandLine : (commandLine + " &");

            return launch;
        }
    };
}

#endif 

 // ******************** From: DiffPrograms.h
#ifndef APPROVALTESTS_CPP_DIFFPROGRAMS_H
#define APPROVALTESTS_CPP_DIFFPROGRAMS_H



#define APPROVAL_TESTS_MACROS_ENTRY(name, defaultValue)                        \
    inline DiffInfo name()                                                     \
    {                                                                          \
        return defaultValue;                                                   \
    }


namespace ApprovalTests
{
    namespace DiffPrograms
    {

        namespace Mac
        {
            APPROVAL_TESTS_MACROS_ENTRY(
                DIFF_MERGE,
                DiffInfo("/Applications/DiffMerge.app/Contents/MacOS/DiffMerge",
                         "{Received} {Approved} -nosplash",
                         Type::TEXT))

            
            APPROVAL_TESTS_MACROS_ENTRY(
                ARAXIS_MERGE,
                DiffInfo(
                    "/Applications/Araxis Merge.app/Contents/Utilities/compare",
                    Type::TEXT_AND_IMAGE))
            

            APPROVAL_TESTS_MACROS_ENTRY(
                BEYOND_COMPARE,
                DiffInfo(
                    "/Applications/Beyond Compare.app/Contents/MacOS/bcomp",
                    Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                KALEIDOSCOPE,
                DiffInfo("/Applications/Kaleidoscope.app/Contents/MacOS/ksdiff",
                         Type::TEXT_AND_IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                KDIFF3,
                DiffInfo("/Applications/kdiff3.app/Contents/MacOS/kdiff3",
                         "{Received} {Approved} -m",
                         Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                P4MERGE,
                DiffInfo("/Applications/p4merge.app/Contents/MacOS/p4merge",
                         Type::TEXT_AND_IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                TK_DIFF,
                DiffInfo("/Applications/TkDiff.app/Contents/MacOS/tkdiff",
                         Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                VS_CODE,
                DiffInfo("/Applications/Visual Studio "
                         "Code.app/Contents/Resources/app/bin/code",
                         "-d {Received} {Approved}",
                         Type::TEXT))
        }

        namespace Linux
        {
            
            APPROVAL_TESTS_MACROS_ENTRY(KDIFF3, DiffInfo("kdiff3", Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(MELD, DiffInfo("meld", Type::TEXT))
        }

        namespace Windows
        {
            APPROVAL_TESTS_MACROS_ENTRY(
                BEYOND_COMPARE_3,
                DiffInfo("{ProgramFiles}Beyond Compare 3\\BCompare.exe",
                         Type::TEXT_AND_IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                BEYOND_COMPARE_4,
                DiffInfo("{ProgramFiles}Beyond Compare 4\\BCompare.exe",
                         Type::TEXT_AND_IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                TORTOISE_IMAGE_DIFF,
                DiffInfo("{ProgramFiles}TortoiseSVN\\bin\\TortoiseIDiff.exe",
                         "/left:{Received} /right:{Approved}",
                         Type::IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                TORTOISE_TEXT_DIFF,
                DiffInfo("{ProgramFiles}TortoiseSVN\\bin\\TortoiseMerge.exe",
                         Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                TORTOISE_GIT_IMAGE_DIFF,
                DiffInfo("{ProgramFiles}TortoiseGit\\bin\\TortoiseGitIDiff.exe",
                         "/left:{Received} /right:{Approved}",
                         Type::IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                TORTOISE_GIT_TEXT_DIFF,
                DiffInfo("{ProgramFiles}TortoiseGit\\bin\\TortoiseGitMerge.exe",
                         Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                WIN_MERGE_REPORTER,
                DiffInfo("{ProgramFiles}WinMerge\\WinMergeU.exe",
                         Type::TEXT_AND_IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                ARAXIS_MERGE,
                DiffInfo("{ProgramFiles}Araxis\\Araxis Merge\\Compare.exe",
                         Type::TEXT_AND_IMAGE))

            APPROVAL_TESTS_MACROS_ENTRY(
                CODE_COMPARE,
                DiffInfo("{ProgramFiles}Devart\\Code Compare\\CodeCompare.exe",
                         Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                KDIFF3,
                DiffInfo("{ProgramFiles}KDiff3\\kdiff3.exe", Type::TEXT))

            APPROVAL_TESTS_MACROS_ENTRY(
                VS_CODE,
                DiffInfo("{ProgramFiles}Microsoft VS Code\\Code.exe",
                         "-d {Received} {Approved}",
                         Type::TEXT))
        }
    }
}

#endif 

 // ******************** From: GenericDiffReporter.h
#ifndef APPROVALTESTS_CPP_GENERICDIFFREPORTER_H
#define APPROVALTESTS_CPP_GENERICDIFFREPORTER_H


namespace ApprovalTests
{
    class GenericDiffReporter : public CommandReporter
    {
    public:
        SystemLauncher launcher;

    public:
        explicit GenericDiffReporter(const std::string& program)
            : CommandReporter(program, &launcher)
        {
        }

        explicit GenericDiffReporter(const DiffInfo& info)
            : CommandReporter(info.getProgramForOs(), info.arguments, &launcher)
        {
        }
    };
}

#endif 

 // ******************** From: FirstWorkingReporter.h
#ifndef APPROVALTESTS_CPP_FIRSTWORKINGREPORTER_H
#define APPROVALTESTS_CPP_FIRSTWORKINGREPORTER_H


namespace ApprovalTests
{
    class FirstWorkingReporter : public Reporter
    {
    private:
        std::vector<std::shared_ptr<Reporter>> reporters;

    public:
        
        explicit FirstWorkingReporter(
            const std::vector<Reporter*>& theReporters)
        {
            for (auto r : theReporters)
            {
                reporters.push_back(std::shared_ptr<Reporter>(r));
            }
        }

        explicit FirstWorkingReporter(
            const std::vector<std::shared_ptr<Reporter>>& reporters)
        {
            this->reporters = reporters;
        }

        bool report(std::string received, std::string approved) const override
        {
            for (auto& r : reporters)
            {
                if (r->report(received, approved))
                {
                    return true;
                }
            }
            return false;
        }
    };
}

#endif 

 // ******************** From: LinuxReporters.h
#ifndef APPROVALTESTS_CPP_LINUXREPORTERS_H
#define APPROVALTESTS_CPP_LINUXREPORTERS_H


namespace ApprovalTests
{
    namespace Linux
    {
        class KDiff3Reporter : public GenericDiffReporter
        {
        public:
            KDiff3Reporter()
                : GenericDiffReporter(DiffPrograms::Linux::KDIFF3())
            {
            }
        };

        class MeldReporter : public GenericDiffReporter
        {
        public:
            MeldReporter() : GenericDiffReporter(DiffPrograms::Linux::MELD())
            {
            }
        };

        class LinuxDiffReporter : public FirstWorkingReporter
        {
        public:
            LinuxDiffReporter()
                : FirstWorkingReporter({
                      
                      new MeldReporter(),
                      new KDiff3Reporter()
                      
                  })
            {
            }
        };
    }
}

#endif 

 // ******************** From: MacReporters.h
#ifndef APPROVALTESTS_CPP_MACREPORTERS_H
#define APPROVALTESTS_CPP_MACREPORTERS_H


namespace ApprovalTests
{
    namespace Mac
    {
        class DiffMergeReporter : public GenericDiffReporter
        {
        public:
            DiffMergeReporter()
                : GenericDiffReporter(DiffPrograms::Mac::DIFF_MERGE())
            {
            }
        };

        
        class AraxisMergeReporter : public GenericDiffReporter
        {
        public:
            AraxisMergeReporter()
                : GenericDiffReporter(DiffPrograms::Mac::ARAXIS_MERGE())
            {
            }
        };
        

        class VisualStudioCodeReporter : public GenericDiffReporter
        {
        public:
            VisualStudioCodeReporter()
                : GenericDiffReporter(DiffPrograms::Mac::VS_CODE())
            {
            }
        };

        class BeyondCompareReporter : public GenericDiffReporter
        {
        public:
            BeyondCompareReporter()
                : GenericDiffReporter(DiffPrograms::Mac::BEYOND_COMPARE())
            {
            }
        };

        class KaleidoscopeReporter : public GenericDiffReporter
        {
        public:
            KaleidoscopeReporter()
                : GenericDiffReporter(DiffPrograms::Mac::KALEIDOSCOPE())
            {
            }
        };

        class KDiff3Reporter : public GenericDiffReporter
        {
        public:
            KDiff3Reporter() : GenericDiffReporter(DiffPrograms::Mac::KDIFF3())
            {
            }
        };

        class P4MergeReporter : public GenericDiffReporter
        {
        public:
            P4MergeReporter()
                : GenericDiffReporter(DiffPrograms::Mac::P4MERGE())
            {
            }
        };

        class TkDiffReporter : public GenericDiffReporter
        {
        public:
            TkDiffReporter() : GenericDiffReporter(DiffPrograms::Mac::TK_DIFF())
            {
            }
        };

        class MacDiffReporter : public FirstWorkingReporter
        {
        public:
            MacDiffReporter()
                : FirstWorkingReporter({
                      
                      new AraxisMergeReporter(),
                      new BeyondCompareReporter(),
                      new DiffMergeReporter(),
                      new KaleidoscopeReporter(),
                      new P4MergeReporter(),
                      new KDiff3Reporter(),
                      new TkDiffReporter(),
                      new VisualStudioCodeReporter()
                      
                  })
            {
            }
        };
    }
}

#endif 

 // ******************** From: WindowsReporters.h
#ifndef APPROVALTESTS_CPP_WINDOWSREPORTERS_H
#define APPROVALTESTS_CPP_WINDOWSREPORTERS_H


namespace ApprovalTests
{
    namespace Windows
    {

        class VisualStudioCodeReporter : public GenericDiffReporter
        {
        public:
            VisualStudioCodeReporter()
                : GenericDiffReporter(DiffPrograms::Windows::VS_CODE())
            {
            }
        };

        
        class BeyondCompare3Reporter : public GenericDiffReporter
        {
        public:
            BeyondCompare3Reporter()
                : GenericDiffReporter(DiffPrograms::Windows::BEYOND_COMPARE_3())
            {
            }
        };

        class BeyondCompare4Reporter : public GenericDiffReporter
        {
        public:
            BeyondCompare4Reporter()
                : GenericDiffReporter(DiffPrograms::Windows::BEYOND_COMPARE_4())
            {
            }
        };

        class BeyondCompareReporter : public FirstWorkingReporter
        {
        public:
            BeyondCompareReporter()
                : FirstWorkingReporter({new BeyondCompare4Reporter(),
                                        new BeyondCompare3Reporter()})
            {
            }
        };

        
        class TortoiseImageDiffReporter : public GenericDiffReporter
        {
        public:
            TortoiseImageDiffReporter()
                : GenericDiffReporter(
                      DiffPrograms::Windows::TORTOISE_IMAGE_DIFF())
            {
            }
        };

        class TortoiseTextDiffReporter : public GenericDiffReporter
        {
        public:
            TortoiseTextDiffReporter()
                : GenericDiffReporter(
                      DiffPrograms::Windows::TORTOISE_TEXT_DIFF())
            {
            }
        };

        class TortoiseDiffReporter : public FirstWorkingReporter
        {
        public:
            TortoiseDiffReporter()
                : FirstWorkingReporter({new TortoiseTextDiffReporter(),
                                        new TortoiseImageDiffReporter()})
            {
            }
        };

        
        class TortoiseGitTextDiffReporter : public GenericDiffReporter
        {
        public:
            TortoiseGitTextDiffReporter()
                : GenericDiffReporter(
                      DiffPrograms::Windows::TORTOISE_GIT_TEXT_DIFF())
            {
            }
        };

        class TortoiseGitImageDiffReporter : public GenericDiffReporter
        {
        public:
            TortoiseGitImageDiffReporter()
                : GenericDiffReporter(
                      DiffPrograms::Windows::TORTOISE_GIT_IMAGE_DIFF())
            {
            }
        };

        class TortoiseGitDiffReporter : public FirstWorkingReporter
        {
        public:
            TortoiseGitDiffReporter()
                : FirstWorkingReporter({new TortoiseGitTextDiffReporter(),
                                        new TortoiseGitImageDiffReporter()})
            {
            }
        };

        
        class WinMergeReporter : public GenericDiffReporter
        {
        public:
            WinMergeReporter()
                : GenericDiffReporter(
                      DiffPrograms::Windows::WIN_MERGE_REPORTER())
            {
            }
        };

        class AraxisMergeReporter : public GenericDiffReporter
        {
        public:
            AraxisMergeReporter()
                : GenericDiffReporter(DiffPrograms::Windows::ARAXIS_MERGE())
            {
            }
        };

        class CodeCompareReporter : public GenericDiffReporter
        {
        public:
            CodeCompareReporter()
                : GenericDiffReporter(DiffPrograms::Windows::CODE_COMPARE())
            {
            }
        };

        class KDiff3Reporter : public GenericDiffReporter
        {
        public:
            KDiff3Reporter()
                : GenericDiffReporter(DiffPrograms::Windows::KDIFF3())
            {
            }
        };

        class WindowsDiffReporter : public FirstWorkingReporter
        {
        public:
            WindowsDiffReporter()
                : FirstWorkingReporter({
                      
                      new TortoiseDiffReporter(), 
                      new TortoiseGitDiffReporter(),
                      new BeyondCompareReporter(),
                      new WinMergeReporter(),
                      new AraxisMergeReporter(),
                      new CodeCompareReporter(),
                      new KDiff3Reporter(),
                      new VisualStudioCodeReporter(),
                      
                  })
            {
            }
        };
    }
}

#endif 

 // ******************** From: DiffReporter.h
#ifndef APPROVALTESTS_CPP_DIFFREPORTER_H
#define APPROVALTESTS_CPP_DIFFREPORTER_H


namespace ApprovalTests
{
    class DiffReporter : public FirstWorkingReporter
    {
    public:
        DiffReporter()
            : FirstWorkingReporter({new Mac::MacDiffReporter(),
                                    new Linux::LinuxDiffReporter(),
                                    new Windows::WindowsDiffReporter()})
        {
        }
    };
}

#endif 

 // ******************** From: DefaultReporterFactory.h
#ifndef APPROVALTESTS_CPP_DEFAULTREPORTERFACTORY_H
#define APPROVALTESTS_CPP_DEFAULTREPORTERFACTORY_H



namespace ApprovalTests
{
    
    class DefaultReporterFactory
    {
        
    private:
        static std::shared_ptr<Reporter>& defaultReporter()
        {
            static std::shared_ptr<Reporter> reporter =
                std::make_shared<DiffReporter>();
            return reporter;
        }

    public:
        static std::shared_ptr<Reporter> getDefaultReporter()
        {
            return defaultReporter();
        }

        static void
        setDefaultReporter(const std::shared_ptr<Reporter>& reporter)
        {
            defaultReporter() = reporter;
        }
        
    };
}

#endif 

 // ******************** From: DefaultReporterDisposer.h
#ifndef APPROVALTESTS_CPP_DEFAULTREPORTERDISPOSER_H
#define APPROVALTESTS_CPP_DEFAULTREPORTERDISPOSER_H


namespace ApprovalTests
{
    
    class APPROVAL_TESTS_NO_DISCARD DefaultReporterDisposer
    {
    private:
        std::shared_ptr<Reporter> previous_result;

    public:
        explicit DefaultReporterDisposer(
            const std::shared_ptr<Reporter>& reporter)
        {
            previous_result = DefaultReporterFactory::getDefaultReporter();
            DefaultReporterFactory::setDefaultReporter(reporter);
        }

        ~DefaultReporterDisposer()
        {
            DefaultReporterFactory::setDefaultReporter(previous_result);
        }
    };
}

#endif 

 // ******************** From: DefaultReporter.h
#ifndef APPROVALTESTS_CPP_DEFAULTREPORTER_H
#define APPROVALTESTS_CPP_DEFAULTREPORTER_H



namespace ApprovalTests
{
    class DefaultReporter : public Reporter
    {
    public:
        virtual bool report(std::string received,
                            std::string approved) const override
        {
            return DefaultReporterFactory::getDefaultReporter()->report(
                received, approved);
        }
    };
}

#endif 

 // ******************** From: SubdirectoryDisposer.h
#ifndef APPROVALTESTS_CPP_SUBDIRECTORYDISPOSER_H
#define APPROVALTESTS_CPP_SUBDIRECTORYDISPOSER_H



namespace ApprovalTests
{
    
    class APPROVAL_TESTS_NO_DISCARD SubdirectoryDisposer
    {
    private:
        std::string previous_result;

    public:
        explicit SubdirectoryDisposer(std::string subdirectory)
        {
            previous_result =
                ApprovalTestNamer::testConfiguration().subdirectory;
            ApprovalTestNamer::testConfiguration().subdirectory =
                std::move(subdirectory);
        }

        ~SubdirectoryDisposer()
        {
            ApprovalTestNamer::testConfiguration().subdirectory =
                previous_result;
        }
    };
}

#endif 

 // ******************** From: DefaultNamerFactory.h
#ifndef APPROVALTESTS_CPP_DEFAULTNAMERFACTORY_H
#define APPROVALTESTS_CPP_DEFAULTNAMERFACTORY_H



namespace ApprovalTests
{

    using NamerCreator = std::function<std::shared_ptr<ApprovalNamer>()>;

    
    class DefaultNamerFactory
    {
    private:
        static NamerCreator& defaultNamer()
        {
            static NamerCreator namer = []() {
                return std::make_shared<ApprovalTestNamer>();
            };
            return namer;
        }

    public:
        static NamerCreator getDefaultNamer()
        {
            return defaultNamer();
        }

        static void setDefaultNamer(NamerCreator namer)
        {
            defaultNamer() = std::move(namer);
        }
    };
}

#endif 

 // ******************** From: ExistingFileNamer.h
#ifndef APPROVALTESTS_CPP_EXISTINGFILENAMER_H
#define APPROVALTESTS_CPP_EXISTINGFILENAMER_H


namespace ApprovalTests
{
    class ExistingFileNamer : public ApprovalNamer
    {
        std::string filePath;

    public:
        explicit ExistingFileNamer(std::string filePath)
            : filePath(std::move(filePath))
        {
        }
        virtual std::string
        getApprovedFile(std::string extensionWithDot) const override
        {
            return DefaultNamerFactory::getDefaultNamer()()->getApprovedFile(
                extensionWithDot);
        }
        virtual std::string
            getReceivedFile(std::string ) const override
        {
            return filePath;
        }
    };
}

#endif 

 // ******************** From: DefaultNamerDisposer.h
#ifndef APPROVALTESTS_CPP_DEFAULTNAMERDISPOSER_H
#define APPROVALTESTS_CPP_DEFAULTNAMERDISPOSER_H


namespace ApprovalTests
{
    
    class APPROVAL_TESTS_NO_DISCARD DefaultNamerDisposer
    {
    private:
        NamerCreator previous_result;

    public:
        explicit DefaultNamerDisposer(NamerCreator namerCreator)
        {
            previous_result = DefaultNamerFactory::getDefaultNamer();
            DefaultNamerFactory::setDefaultNamer(std::move(namerCreator));
        }

        ~DefaultNamerDisposer()
        {
            DefaultNamerFactory::setDefaultNamer(previous_result);
        }
    };
}

#endif 

 // ******************** From: CustomReporter.h
#ifndef APPROVALTESTS_CPP_CUSTOMREPORTER_H
#define APPROVALTESTS_CPP_CUSTOMREPORTER_H


namespace ApprovalTests
{
    class CustomReporter
    {
    public:
        static std::shared_ptr<GenericDiffReporter>
        create(std::string path, Type type = Type::TEXT)
        {
            return create(
                std::move(path), DiffInfo::getDefaultArguments(), type);
        }

        static std::shared_ptr<GenericDiffReporter>
        create(std::string path, std::string arguments, Type type = Type::TEXT)
        {
            DiffInfo info(std::move(path), std::move(arguments), type);
            return std::make_shared<GenericDiffReporter>(info);
        }

        static std::shared_ptr<GenericDiffReporter>
        createForegroundReporter(std::string path, Type type = Type::TEXT)
        {
            return createForegroundReporter(
                std::move(path), DiffInfo::getDefaultArguments(), type);
        }

        static std::shared_ptr<GenericDiffReporter> createForegroundReporter(
            std::string path, std::string arguments, Type type = Type::TEXT)
        {
            DiffInfo info(std::move(path), std::move(arguments), type);
            auto reporter = std::make_shared<GenericDiffReporter>(info);
            reporter->launcher.setForeground(true);
            return reporter;
        }
    };
}

#endif 

 // ******************** From: TextDiffReporter.h
#ifndef APPROVALTESTS_CPP_TEXTDIFFREPORTER_H
#define APPROVALTESTS_CPP_TEXTDIFFREPORTER_H



namespace ApprovalTests
{
    
    
    
    
    class TextDiffReporter : public Reporter
    {
    private:
        std::unique_ptr<Reporter> m_reporter;

    public:
        TextDiffReporter()
        {
            std::vector<std::shared_ptr<Reporter>> reporters = {
                CustomReporter::createForegroundReporter("diff"),
                CustomReporter::createForegroundReporter(
                    "C:/Windows/System32/fc.exe")};
            m_reporter =
                std::unique_ptr<Reporter>(new FirstWorkingReporter(reporters));
        }

        bool report(std::string received, std::string approved) const override
        {
            std::cout << "Comparing files:" << std::endl;
            std::cout << "received: " << received << std::endl;
            std::cout << "approved: " << approved << std::endl;
            const bool result = m_reporter->report(received, approved);
            if (!result)
            {
                std::cout << "TextDiffReporter did not find a working diff "
                             "program\n\n";
            }

            return result;
        }
    };
} 

#endif 

 // ******************** From: CIBuildOnlyReporter.h
#ifndef APPROVALTESTS_CPP_CIBUILDONLYREPORTER_H
#define APPROVALTESTS_CPP_CIBUILDONLYREPORTER_H



namespace ApprovalTests
{
    
    class CIBuildOnlyReporter : public Reporter
    {
    private:
        std::shared_ptr<Reporter> m_reporter;

    public:
        explicit CIBuildOnlyReporter(std::shared_ptr<Reporter> reporter =
                                         std::make_shared<TextDiffReporter>())
            : m_reporter(reporter)
        {
        }

        bool report(std::string received, std::string approved) const override
        {
            if (!isRunningUnderCI())
            {
                return false;
            }
            m_reporter->report(received, approved);
            
            
            return true;
        }

        static bool isRunningUnderCI()
        {
            
            auto environmentVariablesForCI = {
                
                "CI",
                "CONTINUOUS_INTEGRATION",
                "GITHUB_ACTIONS",
                "GO_SERVER_URL",
                "JENKINS_URL",
                "TEAMCITY_VERSION"
                
            };
            for (const auto& variable : environmentVariablesForCI)
            {
                if (!SystemUtils::safeGetEnv(variable).empty())
                {
                    return true;
                }
            }
            return false;
        }
    };
} 

#endif 

 // ******************** From: DefaultFrontLoadedReporter.h
#ifndef APPROVALTESTS_CPP_DEFAULTFRONTLOADEDREPORTER_H
#define APPROVALTESTS_CPP_DEFAULTFRONTLOADEDREPORTER_H


namespace ApprovalTests
{
    class DefaultFrontLoadedReporter : public FirstWorkingReporter
    {
    public:
        DefaultFrontLoadedReporter()
            : FirstWorkingReporter({new CIBuildOnlyReporter()})
        {
        }
    };
}

#endif 

 // ******************** From: FrontLoadedReporterFactory.h
#ifndef APPROVALTESTS_CPP_FRONTLOADEDREPORTERFACTORY_H
#define APPROVALTESTS_CPP_FRONTLOADEDREPORTERFACTORY_H



namespace ApprovalTests
{
    
    class FrontLoadedReporterFactory
    {
        static std::shared_ptr<Reporter>& frontLoadedReporter()
        {
            static std::shared_ptr<Reporter> reporter =
                std::make_shared<DefaultFrontLoadedReporter>();
            return reporter;
        }

    public:
        static std::shared_ptr<Reporter> getFrontLoadedReporter()
        {
            return frontLoadedReporter();
        }

        static void
        setFrontLoadedReporter(const std::shared_ptr<Reporter>& reporter)
        {
            frontLoadedReporter() = reporter;
        }
    };
}

#endif 

 // ******************** From: FrontLoadedReporterDisposer.h
#ifndef APPROVALTESTS_CPP_FRONTLOADEDREPORTERDISPOSER_H
#define APPROVALTESTS_CPP_FRONTLOADEDREPORTERDISPOSER_H


namespace ApprovalTests
{
    
    class APPROVAL_TESTS_NO_DISCARD FrontLoadedReporterDisposer
    {
    private:
        std::shared_ptr<Reporter> previous_result;

    public:
        explicit FrontLoadedReporterDisposer(
            const std::shared_ptr<Reporter>& reporter)
        {
            previous_result =
                FrontLoadedReporterFactory::getFrontLoadedReporter();
            FrontLoadedReporterFactory::setFrontLoadedReporter(reporter);
        }

        ~FrontLoadedReporterDisposer()
        {
            FrontLoadedReporterFactory::setFrontLoadedReporter(previous_result);
        }
    };
}

#endif 

 // ******************** From: ApprovalException.h
#ifndef APPROVALTESTS_CPP_APPROVALEXCEPTION_H
#define APPROVALTESTS_CPP_APPROVALEXCEPTION_H


namespace ApprovalTests
{
    class ApprovalException : public std::exception
    {
    private:
        std::string message;

    public:
        explicit ApprovalException(const std::string& msg) : message(msg)
        {
        }

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
    };

    class ApprovalMismatchException : public ApprovalException
    {
    private:
        std::string format(const std::string& received,
                           const std::string& approved)
        {
            std::stringstream s;
            s << "Failed Approval: \n"
              << "Received does not match approved \n"
              << "Received : \"" << received << "\" \n"
              << "Approved : \"" << approved << "\"";
            return s.str();
        }

    public:
        ApprovalMismatchException(const std::string& received,
                                  const std::string& approved)
            : ApprovalException(format(received, approved))
        {
        }
    };

    class ApprovalMissingException : public ApprovalException
    {
    private:
        std::string format(const std::string& file)
        {
            std::stringstream s;
            s << "Failed Approval: \n"
              << "Approval File Not Found \n"
              << "File: \"" << file << '"';
            return s.str();
        }

    public:
        ApprovalMissingException(const std::string& ,
                                 const std::string& approved)
            : ApprovalException(format(approved))
        {
        }
    };
}

#endif

 // ******************** From: ApprovalComparator.h
#ifndef APPROVALTESTS_CPP_APPROVALCOMPARATOR_H
#define APPROVALTESTS_CPP_APPROVALCOMPARATOR_H


namespace ApprovalTests
{
    class ApprovalComparator
    {
    public:
        virtual ~ApprovalComparator() = default;

        virtual bool contentsAreEquivalent(std::string receivedPath,
                                           std::string approvedPath) const = 0;
    };
}

#endif 

 // ******************** From: TextFileComparator.h
#ifndef APPROVALTESTS_CPP_TEXTFILECOMPARATOR_H
#define APPROVALTESTS_CPP_TEXTFILECOMPARATOR_H


namespace ApprovalTests
{
    class TextFileComparator : public ApprovalComparator
    {
    public:
        static std::ifstream::int_type
        getNextRelevantCharacter(std::ifstream& astream)
        {
            auto ch = astream.get();
            if (ch == '\r')
            {
                return astream.get();
            }
            else
            {
                return ch;
            }
        }

        virtual bool
        contentsAreEquivalent(std::string receivedPath,
                              std::string approvedPath) const override
        {
            std::ifstream astream(approvedPath.c_str(),
                                  std::ios::binary | std::ifstream::in);
            std::ifstream rstream(receivedPath.c_str(),
                                  std::ios::binary | std::ifstream::in);

            while (astream.good() && rstream.good())
            {
                int a = getNextRelevantCharacter(astream);
                int r = getNextRelevantCharacter(rstream);

                if (a != r)
                {
                    return false;
                }
            }
            return true;
        }
    };
}
#endif 

 // ******************** From: ComparatorDisposer.h
#ifndef APPROVALTESTS_CPP_COMPARATORDISPOSER_H
#define APPROVALTESTS_CPP_COMPARATORDISPOSER_H


namespace ApprovalTests
{

    using ComparatorContainer =
        std::map<std::string, std::shared_ptr<ApprovalComparator>>;

    class APPROVAL_TESTS_NO_DISCARD ComparatorDisposer
    {
    public:
        ComparatorDisposer(
            ComparatorContainer& comparators,
            const std::string& extensionWithDot,
            std::shared_ptr<ApprovalTests::ApprovalComparator>
                previousComparator,
            std::shared_ptr<ApprovalTests::ApprovalComparator> newComparator)
            : comparators(comparators)
            , ext_(extensionWithDot)
            , previousComparator(std::move(previousComparator))
        {
            comparators[extensionWithDot] = std::move(newComparator);
        }

        ComparatorDisposer(const ComparatorDisposer&) = delete;

        ComparatorDisposer(ComparatorDisposer&& other) noexcept
            : comparators(other.comparators)
            , ext_(std::move(other.ext_))
            , previousComparator(std::move(other.previousComparator))
        {
            other.isActive = false;
        }

        ~ComparatorDisposer()
        {
            if (isActive)
            {
                comparators[ext_] = previousComparator;
            }
        }

    private:
        
        
        bool isActive = true;
        ComparatorContainer& comparators;
        std::string ext_;
        std::shared_ptr<ApprovalTests::ApprovalComparator> previousComparator;
    };
}

#endif 

 // ******************** From: ComparatorFactory.h
#ifndef APPROVALTESTS_CPP_COMPARATORFACTORY_H
#define APPROVALTESTS_CPP_COMPARATORFACTORY_H


namespace ApprovalTests
{

    class ComparatorFactory
    {
    private:
        static ComparatorContainer& comparators()
        {
            static ComparatorContainer allComparators;
            return allComparators;
        }

    public:
        static ComparatorDisposer
        registerComparator(const std::string& extensionWithDot,
                           std::shared_ptr<ApprovalComparator> comparator)
        {
            return ComparatorDisposer(
                comparators(),
                extensionWithDot,
                getComparatorForFileExtensionWithDot(extensionWithDot),
                comparator);
        }

        static std::shared_ptr<ApprovalComparator>
        getComparatorForFile(const std::string& receivedPath)
        {
            const std::string fileExtension =
                FileUtils::getExtensionWithDot(receivedPath);
            return getComparatorForFileExtensionWithDot(fileExtension);
        }

        static std::shared_ptr<ApprovalComparator>
        getComparatorForFileExtensionWithDot(
            const std::string& fileExtensionWithDot)
        {
            auto iterator = comparators().find(fileExtensionWithDot);
            if (iterator != comparators().end())
            {
                return iterator->second;
            }
            return std::make_shared<TextFileComparator>();
        }
    };
}

#endif 

 // ******************** From: FileApprover.h
#ifndef APPROVALTESTS_CPP_FILEAPPROVER_H
#define APPROVALTESTS_CPP_FILEAPPROVER_H


namespace ApprovalTests
{

    class FileApprover
    {

    public:
        FileApprover() = default;

        ~FileApprover() = default;

        static ComparatorDisposer registerComparatorForExtension(
            const std::string& extensionWithDot,
            std::shared_ptr<ApprovalComparator> comparator)
        {
            return ComparatorFactory::registerComparator(extensionWithDot,
                                                         comparator);
        }

        
        static void verify(const std::string& receivedPath,
                           const std::string& approvedPath,
                           const ApprovalComparator& comparator)
        {
            if (!FileUtils::fileExists(approvedPath))
            {
                throw ApprovalMissingException(receivedPath, approvedPath);
            }

            if (!FileUtils::fileExists(receivedPath))
            {
                throw ApprovalMissingException(approvedPath, receivedPath);
            }

            if (!comparator.contentsAreEquivalent(receivedPath, approvedPath))
            {
                throw ApprovalMismatchException(receivedPath, approvedPath);
            }
        }

        static void verify(const std::string& receivedPath,
                           const std::string& approvedPath)
        {
            verify(receivedPath,
                   approvedPath,
                   *ComparatorFactory::getComparatorForFile(receivedPath));
        }

        static void verify(const ApprovalNamer& n,
                           const ApprovalWriter& s,
                           const Reporter& r)
        {
            std::string approvedPath =
                n.getApprovedFile(s.getFileExtensionWithDot());
            std::string receivedPath =
                n.getReceivedFile(s.getFileExtensionWithDot());
            s.write(receivedPath);
            try
            {
                verify(receivedPath, approvedPath);
                s.cleanUpReceived(receivedPath);
            }
            catch (const ApprovalException&)
            {
                reportAfterTryingFrontLoadedReporter(
                    receivedPath, approvedPath, r);
                throw;
            }
        }

        static void
        reportAfterTryingFrontLoadedReporter(const std::string& receivedPath,
                                             const std::string& approvedPath,
                                             const Reporter& r)
        {
            auto tryFirst =
                FrontLoadedReporterFactory::getFrontLoadedReporter();
            if (!tryFirst->report(receivedPath, approvedPath))
            {
                r.report(receivedPath, approvedPath);
            }
        }
    };
}

#endif

 // ******************** From: Approvals.h
#ifndef APPROVALTESTS_CPP_APPROVALS_H
#define APPROVALTESTS_CPP_APPROVALS_H



namespace ApprovalTests
{
    class Approvals
    {
    private:
        Approvals() = default;

        ~Approvals() = default;

    public:
        static std::shared_ptr<ApprovalNamer> getDefaultNamer()
        {
            return DefaultNamerFactory::getDefaultNamer()();
        }

        static void verify(std::string contents,
                           const Reporter& reporter = DefaultReporter())
        {
            verifyWithExtension(contents, ".txt", reporter);
        }

        static void
        verifyWithExtension(std::string contents,
                            const std::string& fileExtensionWithDot,
                            const Reporter& reporter = DefaultReporter())
        {
            StringWriter writer(contents, fileExtensionWithDot);
            FileApprover::verify(*getDefaultNamer(), writer, reporter);
        }

        static void verify(const ApprovalWriter& writer,
                           const Reporter& reporter = DefaultReporter())
        {
            FileApprover::verify(*getDefaultNamer(), writer, reporter);
        }

        template <typename T>
        using IsNotDerivedFromWriter =
            typename std::enable_if<!std::is_base_of<ApprovalWriter, T>::value,
                                    int>::type;

        template <typename T, typename = IsNotDerivedFromWriter<T>>
        static void verify(const T& contents,
                           const Reporter& reporter = DefaultReporter())
        {
            verify(StringUtils::toString(contents), reporter);
        }

        template <typename T, typename = IsNotDerivedFromWriter<T>>
        static void
        verifyWithExtension(const T& contents,
                            const std::string& fileExtensionWithDot,
                            const Reporter& reporter = DefaultReporter())
        {
            verifyWithExtension(StringUtils::toString(contents),
                                fileExtensionWithDot,
                                reporter);
        }

        template <typename T,
                  typename Function,
                  typename = Detail::EnableIfNotDerivedFromReporter<Function>>
        static void verify(const T& contents,
                           Function converter,
                           const Reporter& reporter = DefaultReporter())
        {
            std::stringstream s;
            converter(contents, s);
            verify(s.str(), reporter);
        }

        template <typename T,
                  typename Function,
                  typename = Detail::EnableIfNotDerivedFromReporter<Function>>
        static void
        verifyWithExtension(const T& contents,
                            Function converter,
                            const std::string& fileExtensionWithDot,
                            const Reporter& reporter = DefaultReporter())
        {
            std::stringstream s;
            converter(contents, s);
            verifyWithExtension(s.str(), fileExtensionWithDot, reporter);
        }

        static void
        verifyExceptionMessage(std::function<void(void)> functionThatThrows,
                               const Reporter& reporter = DefaultReporter())
        {
            std::string message = "*** no exception thrown ***";
            try
            {
                functionThatThrows();
            }
            catch (const std::exception& e)
            {
                message = e.what();
            }
            verify(message, reporter);
        }

        template <typename Iterator>
        static void verifyAll(std::string header,
                              const Iterator& start,
                              const Iterator& finish,
                              std::function<void(typename Iterator::value_type,
                                                 std::ostream&)> converter,
                              const Reporter& reporter = DefaultReporter())
        {
            std::stringstream s;
            if (!header.empty())
            {
                s << header << "\n\n\n";
            }
            for (auto it = start; it != finish; ++it)
            {
                converter(*it, s);
                s << '\n';
            }
            verify(s.str(), reporter);
        }

        template <typename Container>
        static void verifyAll(std::string header,
                              const Container& list,
                              std::function<void(typename Container::value_type,
                                                 std::ostream&)> converter,
                              const Reporter& reporter = DefaultReporter())
        {
            verifyAll<typename Container::const_iterator>(
                header, list.begin(), list.end(), converter, reporter);
        }

        template <typename T>
        static void verifyAll(std::string header,
                              const std::vector<T>& list,
                              const Reporter& reporter = DefaultReporter())
        {
            int i = 0;
            verifyAll<std::vector<T>>(
                header,
                list,
                [&](T e, std::ostream& s) { s << "[" << i++ << "] = " << e; },
                reporter);
        }

        template <typename T>
        static void verifyAll(const std::vector<T>& list,
                              const Reporter& reporter = DefaultReporter())
        {
            verifyAll<T>("", list, reporter);
        }

        static void
        verifyExistingFile(const std::string filePath,
                           const Reporter& reporter = DefaultReporter())
        {
            ExistingFile writer(filePath);
            ExistingFileNamer namer(filePath);
            FileApprover::verify(namer, writer, reporter);
        }

        static SubdirectoryDisposer
        useApprovalsSubdirectory(std::string subdirectory = "approval_tests")
        {
            return SubdirectoryDisposer(subdirectory);
        }

        static DefaultReporterDisposer
        useAsDefaultReporter(const std::shared_ptr<Reporter>& reporter)
        {
            return DefaultReporterDisposer(reporter);
        }

        static FrontLoadedReporterDisposer
        useAsFrontLoadedReporter(const std::shared_ptr<Reporter>& reporter)
        {
            return FrontLoadedReporterDisposer(reporter);
        }

        static DefaultNamerDisposer useAsDefaultNamer(NamerCreator namerCreator)
        {
            return DefaultNamerDisposer(namerCreator);
        }
    };
}

#endif

 // ******************** From: CombinationApprovals.h
#ifndef APPROVALTESTS_CPP_COMBINATIONAPPROVALS_H
#define APPROVALTESTS_CPP_COMBINATIONAPPROVALS_H


namespace ApprovalTests
{
    namespace CombinationApprovals
    {
        namespace Detail
        {

            
            struct print_input
            {
                std::ostream& out;
                template <class T> void operator()(const T& input)
                {
                    out << ", " << input;
                }
            };

            
            template <class Converter> struct serialize
            {
                std::ostream& out;
                Converter converter;
                template <class T, class... Ts>
                void operator()(T&& input1, Ts&&... inputs)
                {
                    
                    out << "(" << input1;
                    
                    CartesianProduct::Detail::for_each(
                        std::forward_as_tuple(inputs...), print_input{out});
                    out << ") => " << converter(input1, inputs...) << '\n';
                }
            };
        } 

        template <class Converter, class Container, class... Containers>
        void verifyAllCombinations(const Reporter& reporter,
                                   Converter&& converter,
                                   const Container& input0,
                                   const Containers&... inputs)
        {
            std::stringstream s;
            CartesianProduct::cartesian_product(
                Detail::serialize<Converter>{
                    s, std::forward<Converter>(converter)},
                input0,
                inputs...);
            Approvals::verify(s.str(), reporter);
        }

        template <class Converter, class... Containers>
        ApprovalTests::Detail::EnableIfNotDerivedFromReporter<Converter>
        verifyAllCombinations(Converter&& converter,
                              const Containers&... inputs)
        {
            verifyAllCombinations(DefaultReporter(),
                                  std::forward<Converter>(converter),
                                  inputs...);
        }

    } 
} 

#endif

 // ******************** From: CheckFileMacroIsAbsolute.h
#ifndef APPROVALTESTS_CPP_CHECKFILEMACROISABSOLUTE_H
#define APPROVALTESTS_CPP_CHECKFILEMACROISABSOLUTE_H




// <SingleHpp unalterable>
//
// This static_assert can be disabled by
// defining APPROVALS_CATCH_DISABLE_FILE_MACRO_CHECK.
// This can be done on the CMake command line with:
// -DCMAKE_CXX_FLAGS_INIT=-DAPPROVALS_CATCH_DISABLE_FILE_MACRO_CHECK
//
// ApprovalTests will then check the validity of __FILE__
// at run-time instead, for test frameworks that use it to
// detect the source file name.
#ifndef APPROVALS_CATCH_DISABLE_FILE_MACRO_CHECK
// clang-format off
static_assert(
    (__FILE__[1] == ':') ||
    (__FILE__[0] == '/'),
              // begin-snippet: compiler_error_for_misconfigured_build
"There seems to be a problem with your build configuration, probably with Ninja. "
"Please visit https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TroubleshootingMisconfiguredBuild.md "
"The filename is: "
__FILE__
              // end-snippet
              // clang-format on
);
#endif // APPROVALS_CATCH_DISABLE_FILE_MACRO_CHECK
// </SingleHpp>

#endif 

 // ******************** From: Catch2Approvals.h

#ifndef APPROVALTESTS_CPP_CATCH2APPROVALS_H
#define APPROVALTESTS_CPP_CATCH2APPROVALS_H


// <SingleHpp unalterable>
#if defined(APPROVALS_CATCH_EXISTING_MAIN)
#define APPROVALS_CATCH
#define CATCH_CONFIG_RUNNER
#elif defined(APPROVALS_CATCH)
#define CATCH_CONFIG_MAIN
#endif

#ifdef APPROVALS_CATCH
// begin-snippet: required_header_for_catch
#include <catch2/catch.hpp>
// end-snippet

//namespace ApprovalTests {
struct Catch2ApprovalListener : Catch::TestEventListenerBase
{
    ApprovalTests::TestName currentTest;
    using TestEventListenerBase::
        TestEventListenerBase; // This using allows us to use all base-class constructors
    virtual void testCaseStarting(Catch::TestCaseInfo const& testInfo) override
    {

        currentTest.setFileName(testInfo.lineInfo.file);
        ApprovalTests::ApprovalTestNamer::currentTest(&currentTest);
    }

    virtual void
    testCaseEnded(Catch::TestCaseStats const& /*testCaseStats*/) override
    {
        while (!currentTest.sections.empty())
        {
            currentTest.sections.pop_back();
        }
    }

    virtual void sectionStarting(Catch::SectionInfo const& sectionInfo) override
    {
        currentTest.sections.push_back(sectionInfo.name);
    }

    virtual void
    sectionEnded(Catch::SectionStats const& /*sectionStats*/) override
    {
        currentTest.sections.pop_back();
    }
};
//}
CATCH_REGISTER_LISTENER(Catch2ApprovalListener)

#endif
#ifdef TEST_COMMIT_REVERT_CATCH

//namespace ApprovalTests {
struct Catch2TestCommitRevert : Catch::TestEventListenerBase
{
    using TestEventListenerBase::
        TestEventListenerBase; // This using allows us to use all base-class constructors
    virtual void testRunEnded(Catch::TestRunStats const& testRunStats) override
    {
        bool commit = testRunStats.totals.testCases.allOk();
        std::string message = "r ";
        if (commit)
        {
            std::cout << "git add -A n";
            std::cout << "git commit -m " << message;
        }
        else
        {
            std::cout << "git clean -fd n";
            std::cout << "git reset --hard HEAD n";
        }
    }
};
//}
CATCH_REGISTER_LISTENER(Catch2TestCommitRevert)
#endif
// </SingleHpp>
#endif 

 // ******************** From: DocTestApprovals.h
#ifndef APPROVALTESTS_CPP_DOCTESTAPPROVALS_H
#define APPROVALTESTS_CPP_DOCTESTAPPROVALS_H


// <SingleHpp unalterable>
#ifdef APPROVALS_DOCTEST

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// begin-snippet: required_header_for_doctest
#include <doctest/doctest.h>
// end-snippet

namespace ApprovalTests
{
    // anonymous namespace to prevent compiler -Wsubobject-linkage warnings
    // This is OK as this code is only compiled on main()
    namespace
    {
        struct AbstractReporter : doctest::IReporter
        {
            virtual void report_query(const doctest::QueryData&) override
            {
            }
            // called when the whole test run starts
            virtual void test_run_start() override
            {
            }

            // called when the whole test run ends (caching a pointer to the input doesn't make sense here)
            virtual void test_run_end(const doctest::TestRunStats&) override
            {
            }

            // called when a test case is started (safe to cache a pointer to the input)
            virtual void test_case_start(const doctest::TestCaseData&) override
            {
            }

#if 20305 <= DOCTEST_VERSION
            // called when a test case is reentered because of unfinished subcases (safe to cache a pointer to the input)
            virtual void
            test_case_reenter(const doctest::TestCaseData&) override
            {
            }
#endif

            // called when a test case has ended
            virtual void
            test_case_end(const doctest::CurrentTestCaseStats&) override
            {
            }

            // called when an exception is thrown from the test case (or it crashes)
            virtual void
            test_case_exception(const doctest::TestCaseException&) override
            {
            }

            // called whenever a subcase is entered (don't cache pointers to the input)
            virtual void
            subcase_start(const doctest::SubcaseSignature&) override
            {
            }

            // called whenever a subcase is exited (don't cache pointers to the input)
            virtual void subcase_end() override
            {
            }

            // called for each assert (don't cache pointers to the input)
            virtual void log_assert(const doctest::AssertData&) override
            {
            }

            // called for each message (don't cache pointers to the input)
            virtual void log_message(const doctest::MessageData&) override
            {
            }

            // called when a test case is skipped either because it doesn't pass the filters, has a skip decorator
            // or isn't in the execution range (between first and last) (safe to cache a pointer to the input)
            virtual void
            test_case_skipped(const doctest::TestCaseData&) override
            {
            }
        };

        struct DocTestApprovalListener : AbstractReporter
        {
            TestName currentTest;

            // constructor has to accept the ContextOptions by ref as a single argument
            explicit DocTestApprovalListener(
                const doctest::ContextOptions& /*in*/)
            {
            }

            void test_case_start(const doctest::TestCaseData& testInfo) override
            {

                currentTest.sections.emplace_back(testInfo.m_name);
                currentTest.setFileName(testInfo.m_file);
                ApprovalTestNamer::currentTest(&currentTest);
            }

            void
            test_case_end(const doctest::CurrentTestCaseStats& /*in*/) override
            {

                while (!currentTest.sections.empty())
                {
                    currentTest.sections.pop_back();
                }
            }

            void
            subcase_start(const doctest::SubcaseSignature& signature) override
            {

                currentTest.sections.emplace_back(signature.m_name);
            }

            void subcase_end() override
            {

                currentTest.sections.pop_back();
            }
        };
    }
}

REGISTER_LISTENER("approvals", 0, ApprovalTests::DocTestApprovalListener);

#endif // APPROVALS_DOCTEST
// </SingleHpp>
#endif 

 // ******************** From: GoogleConfiguration.h
#ifndef APPROVALTESTS_CPP_GOOGLECONFIGURATION_H
#define APPROVALTESTS_CPP_GOOGLECONFIGURATION_H


namespace ApprovalTests
{
    class GoogleConfiguration
    {
    public:
        
        APPROVAL_TESTS_NO_DISCARD static bool addTestCaseNameRedundancyCheck(
            GoogleCustomizationsFactory::Comparator comparator)
        {
            return GoogleCustomizationsFactory::addTestCaseNameRedundancyCheck(
                comparator);
        }

        
        APPROVAL_TESTS_NO_DISCARD static bool
        addIgnorableTestCaseNameSuffix(std::string suffix)
        {
            return addTestCaseNameRedundancyCheck(
                createIgnorableTestCaseNameSuffixCheck(suffix));
        }

        static GoogleCustomizationsFactory::Comparator
        createIgnorableTestCaseNameSuffixCheck(const std::string& suffix)
        {
            return [suffix](std::string testFileNameWithExtension,
                            std::string testCaseName) {
                if (testCaseName.length() <= suffix.length() ||
                    !StringUtils::endsWith(testCaseName, suffix))
                {
                    return false;
                }

                auto withoutSuffix = testCaseName.substr(
                    0, testCaseName.length() - suffix.length());
                auto withFileExtension = withoutSuffix + ".";
                return StringUtils::contains(testFileNameWithExtension,
                                             withFileExtension);
            };
        }
    };
}

#endif 

 // ******************** From: GoogleTestApprovals.h
#ifndef APPROVALTESTS_CPP_GOOGLTESTAPPPROVALS_H
#define APPROVALTESTS_CPP_GOOGLTESTAPPPROVALS_H


#ifdef APPROVALS_GOOGLETEST_EXISTING_MAIN
#define APPROVALS_GOOGLETEST
#endif

#ifdef APPROVALS_GOOGLETEST

// <SingleHpp unalterable>
#include "gtest/gtest.h"

namespace ApprovalTests
{
    class GoogleTestListener : public testing::EmptyTestEventListener
    {
        TestName currentTest;

    public:
        bool isDuplicate(std::string testFileNameWithExtension,
                         std::string testCaseName)
        {
            for (auto check :
                 GoogleCustomizationsFactory::getEquivalencyChecks())
            {
                if (check(testFileNameWithExtension, testCaseName))
                {
                    return true;
                }
            }
            return false;
        }

        virtual void OnTestStart(const testing::TestInfo& testInfo) override
        {
            currentTest.setFileName(testInfo.file());
            currentTest.sections = {};
            if (!isDuplicate(currentTest.getFileName(),
                             testInfo.test_case_name()))
            {
                currentTest.sections.emplace_back(testInfo.test_case_name());
            }
            if (!std::string(testInfo.name()).empty())
            {
                currentTest.sections.emplace_back(testInfo.name());
            }

            ApprovalTestNamer::currentTest(&currentTest);
        }
    };

    inline void initializeApprovalTestsForGoogleTests()
    {
        auto& listeners = testing::UnitTest::GetInstance()->listeners();
        listeners.Append(new GoogleTestListener);
    }
}

#ifndef APPROVALS_GOOGLETEST_EXISTING_MAIN
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ApprovalTests::initializeApprovalTestsForGoogleTests();
    return RUN_ALL_TESTS();
}
#endif //APPROVALS_GOOGLETEST_EXISTING_MAIN

// </SingleHpp>
#endif
#endif 

 // ******************** From: UTApprovals.h
#ifndef APPROVALTESTS_CPP_UTAPPROVALS_H
#define APPROVALTESTS_CPP_UTAPPROVALS_H


// <SingleHpp unalterable>
#ifdef APPROVALS_UT

#if !(__GNUC__ >= 9 or __clang_major__ >= 9)
#error                                                                         
    "The [Boost].UT integration with Approval Tests requires source_location support by the compiler"
#endif

// begin-snippet: required_header_for_ut
#include <boost/ut.hpp>
// end-snippet

namespace ApprovalTests
{
    namespace cfg
    {
        class reporter : public boost::ut::reporter<boost::ut::printer>
        {
        private:
            TestName currentTest;

        public:
            auto on(boost::ut::events::test_begin test_begin) -> void
            {
                std::string name = test_begin.name;
                currentTest.sections.emplace_back(name);
                currentTest.setFileName(test_begin.location.file_name());

                ApprovalTestNamer::currentTest(&currentTest);

                boost::ut::reporter<boost::ut::printer>::on(test_begin);
            }

            auto on(boost::ut::events::test_run test_run) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(test_run);
            }

            auto on(boost::ut::events::test_skip test_skip) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(test_skip);
            }

            auto on(boost::ut::events::test_end test_end) -> void
            {
                while (!currentTest.sections.empty())
                {
                    currentTest.sections.pop_back();
                }
                boost::ut::reporter<boost::ut::printer>::on(test_end);
            }

            template <class TMsg>
            auto on(boost::ut::events::log<TMsg> log) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(log);
            }

            template <class TExpr>
            auto on(boost::ut::events::assertion_pass<TExpr> location) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(location);
            }

            template <class TExpr>
            auto on(boost::ut::events::assertion_fail<TExpr> fail) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(fail);
            }

            auto on(boost::ut::events::fatal_assertion fatal) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(fatal);
            }

            auto on(boost::ut::events::exception exception) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(exception);
            }

            auto on(boost::ut::events::summary summary) -> void
            {
                boost::ut::reporter<boost::ut::printer>::on(summary);
            }
        };
    } // namespace cfg
}

template <>
auto boost::ut::cfg<boost::ut::override> =
    boost::ut::runner<ApprovalTests::cfg::reporter>{};

#endif // APPROVALS_UT
// </SingleHpp>
#endif 

 // ******************** From: NamerFactory.h
#ifndef APPROVALTESTS_CPP_NAMERFACTORY_H
#define APPROVALTESTS_CPP_NAMERFACTORY_H



namespace ApprovalTests
{
    struct NamerFactory
    {
        static SectionNameDisposer
        appendToOutputFilename(const std::string& sectionName)
        {
            return SectionNameDisposer(ApprovalTestNamer::currentTest(),
                                       sectionName);
        }
    };
}

#endif 

 // ******************** From: SeparateApprovedAndReceivedDirectoriesNamer.h
#ifndef APPROVALTESTS_CPP_SEPARATEAPPROVEDANDRECEIVEDDIRECTORIESNAMER_H
#define APPROVALTESTS_CPP_SEPARATEAPPROVEDANDRECEIVEDDIRECTORIESNAMER_H


namespace ApprovalTests
{
    class SeparateApprovedAndReceivedDirectoriesNamer : public ApprovalTestNamer
    {
    public:
        virtual ~SeparateApprovedAndReceivedDirectoriesNamer() override =
            default;

        std::string getFullFileNameWithExtraDirectory(
            const std::string& approved,
            const std::string& extensionWithDot) const
        {
            std::string outputDirectory = getDirectory() + approved;
            SystemUtils::ensureDirectoryExists(outputDirectory);

            std::string outputFile =
                getFileName() + "." + getTestName() + extensionWithDot;

            return outputDirectory + SystemUtils::getDirectorySeparator() +
                   outputFile;
        }

        virtual std::string
        getApprovedFile(std::string extensionWithDot) const override
        {
            return getFullFileNameWithExtraDirectory("approved",
                                                     extensionWithDot);
        }

        virtual std::string
        getReceivedFile(std::string extensionWithDot) const override
        {
            return getFullFileNameWithExtraDirectory("received",
                                                     extensionWithDot);
        }

        static DefaultNamerDisposer useAsDefaultNamer()
        {
            return Approvals::useAsDefaultNamer([]() {
                return std::make_shared<
                    SeparateApprovedAndReceivedDirectoriesNamer>();
            });
        }
    };
}

#endif 

 // ******************** From: AutoApproveIfMissingReporter.h
#ifndef APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H
#define APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H


namespace ApprovalTests
{
    class AutoApproveIfMissingReporter : public Reporter
    {
    public:
        bool report(std::string received, std::string approved) const override
        {
            if (FileUtils::fileExists(approved))
            {
                return false;
            }

            return AutoApproveReporter().report(received, approved);
        }
    };
}

#endif 

 // ******************** From: BlockingReporter.h
#ifndef APPROVALTESTS_CPP_BLOCKINGREPORTER_H
#define APPROVALTESTS_CPP_BLOCKINGREPORTER_H



namespace ApprovalTests
{
    class BlockingReporter : public Reporter
    {
    private:
        std::shared_ptr<Blocker> blocker;

        BlockingReporter() = delete;

    public:
        explicit BlockingReporter(std::shared_ptr<Blocker> blocker)
            : blocker(std::move(blocker))
        {
        }

        static std::shared_ptr<BlockingReporter>
        onMachineNamed(const std::string& machineName)
        {
            auto machineBlocker = std::make_shared<MachineBlocker>(
                MachineBlocker::onMachineNamed(machineName));
            return std::make_shared<BlockingReporter>(machineBlocker);
        }

        static std::shared_ptr<BlockingReporter>
        onMachinesNotNamed(const std::string& machineName)
        {
            auto machineBlocker = std::make_shared<MachineBlocker>(
                MachineBlocker::onMachinesNotNamed(machineName));
            return std::make_shared<BlockingReporter>(machineBlocker);
        }

        virtual bool report(std::string ,
                            std::string ) const override
        {
            return blocker->isBlockingOnThisMachine();
        }
    };
}

#endif 

 // ******************** From: CIBuildOnlyReporterUtils.h
#ifndef APPROVALTESTS_CPP_CIBUILDONLYREPORTERUTILS_H
#define APPROVALTESTS_CPP_CIBUILDONLYREPORTERUTILS_H


namespace ApprovalTests
{
    namespace CIBuildOnlyReporterUtils
    {
        inline FrontLoadedReporterDisposer
        useAsFrontLoadedReporter(const std::shared_ptr<Reporter>& reporter)
        {
            return Approvals::useAsFrontLoadedReporter(
                std::make_shared<ApprovalTests::CIBuildOnlyReporter>(reporter));
        }
    }
} 

#endif 

 // ******************** From: ClipboardReporter.h
#ifndef APPROVALTESTS_CPP_COMMANDLINEREPORTER_H
#define APPROVALTESTS_CPP_COMMANDLINEREPORTER_H



namespace ApprovalTests
{
    class ClipboardReporter : public Reporter
    {
    public:
        static std::string getCommandLineFor(const std::string& received,
                                             const std::string& approved,
                                             bool isWindows)
        {
            if (isWindows)
            {
                return std::string("move /Y ") + "\"" + received + "\" \"" +
                       approved + "\"";
            }
            else
            {
                return std::string("mv ") + "\"" + received + "\" \"" +
                       approved + "\"";
            }
        }

        virtual bool report(std::string received,
                            std::string approved) const override
        {
            copyToClipboard(getCommandLineFor(
                received, approved, SystemUtils::isWindowsOs()));
            return true;
        }

        static void copyToClipboard(const std::string& newClipboard)
        {
            

            std::string clipboardCommand;
            if (SystemUtils::isWindowsOs())
            {
                clipboardCommand = "clip";
            }
            else if (SystemUtils::isMacOs())
            {
                clipboardCommand = "pbcopy";
            }
            else
            {
                clipboardCommand = "pbclip";
            }
            auto cmd =
                std::string("echo ") + newClipboard + " | " + clipboardCommand;
            SystemUtils::runSystemCommandOrThrow(cmd);
        }
    };
}

#endif 

 // ******************** From: CombinationReporter.h
#ifndef APPROVALTESTS_CPP_COMBINATIONREPORTER_H
#define APPROVALTESTS_CPP_COMBINATIONREPORTER_H


namespace ApprovalTests
{
    class CombinationReporter : public Reporter
    {
    private:
        std::vector<std::unique_ptr<Reporter>> reporters;

    public:
        
        explicit CombinationReporter(const std::vector<Reporter*>& theReporters)
        {
            for (auto r : theReporters)
            {
                reporters.push_back(std::unique_ptr<Reporter>(r));
            }
        }

        bool report(std::string received, std::string approved) const override
        {
            bool result = false;
            for (auto& r : reporters)
            {
                result |= r->report(received, approved);
            }
            return result;
        }
    };
}

#endif 

 // ******************** From: ExceptionCollector.h
#ifndef APPROVALTESTS_CPP_EXCEPTIONCOLLECTOR_H
#define APPROVALTESTS_CPP_EXCEPTIONCOLLECTOR_H


namespace ApprovalTests
{
    class ExceptionCollector
    {
        std::vector<std::string> exceptionMessages;

    public:
        void gather(std::function<void(void)> functionThatThrows)
        {
            try
            {
                functionThatThrows();
            }
            catch (const std::exception& e)
            {
                exceptionMessages.emplace_back(e.what());
            }
        }
        ~ExceptionCollector()
        {
            if (!exceptionMessages.empty())
            {
                exceptionMessages.emplace_back(
                    "ERROR: Calling code forgot to call "
                    "exceptionCollector.release()");
            }
            release();
        }

        void release()
        {
            if (!exceptionMessages.empty())
            {
                std::stringstream s;
                s << exceptionMessages.size() << " exceptions were thrown:\n\n";
                int count = 1;
                for (const auto& error : exceptionMessages)
                {
                    s << count++ << ") " << error << '\n';
                }
                exceptionMessages.clear();
                throw std::runtime_error(s.str());
            }
        }
    };
}

#endif 


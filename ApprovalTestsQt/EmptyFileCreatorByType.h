#pragma once

namespace ApprovalTestsQt
{
    class EmptyFileCreatorByType
    {
    public:
        static std::map<std::string, ApprovalTests::EmptyFileCreator> creators_;

        static void registerCreator(const std::string& extensionWithDot,
                                    ApprovalTests::EmptyFileCreator creator)
        {
            creators_[extensionWithDot] = std::move(creator);
        }

        static void createFile(const std::string& fileName)
        {
            for (const auto& creator : creators_)
            {
                if (ApprovalTests::StringUtils::endsWith(fileName, creator.first))
                {
                    creator.second(fileName);
                    return;
                }
            }
            std::string contents;
            ApprovalTests::StringWriter s(contents);
            s.write(fileName);
        }
    };

#ifdef APPROVALS_CATCH_QT
    std::map<std::string, ApprovalTests::EmptyFileCreator>
        EmptyFileCreatorByType::creators_;
#endif
}

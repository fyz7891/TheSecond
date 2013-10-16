
using namespace gaia::base;
class ISmsSdInternalBackup: public StubSdInternalInterface {
public:
	ISmsSdInternalBackup(gaia::core::Context *pContext);
    virtual ~ISmsSdInternalBackup();
    
    virtual int32_t onBackup( gaia::base::String folderPath );

    virtual int32_t onRestore( gaia::base::String folderPath, int32_t restoreCount );

    virtual void onCancel();

    virtual int32_t getBackupCount();
    
    virtual gaia::base::String getAgentSpecificErrorString(int32_t errorCode);

    virtual void setCallback( IProgressUpdater* callback );

	void ensureDirectory(String dirName);
	bool fileExist(String dirName, String fileName);
	int readVMsg(String filePath);
private:

    gaia::core::Context *mpContext;
    IProgressUpdater* mpProgressUpdater;
    bool mCancel;
};

#endif  // __ISD_INTERNAL_BACKUP_H__

const { app, BrowserWindow, ipcMain, webFrame } = require('electron');
const path = require("path");
const fs = require("fs");

app.disableHardwareAcceleration();

function createWindow () {
  const win = new BrowserWindow({
    width: 360,
    height: 720,
	resizable: true,
	frame: false,
	webPreferences: {
			preload: path.join(__dirname,'./scripts/browser.js'),
			nativeWindowOpen: false,
			contextIsolation: false,
			enableRemoteModule: true
		}
  })

  win.loadURL('https://messenger.com/')
	

}

app.whenReady().then(createWindow)

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow()
  }
})




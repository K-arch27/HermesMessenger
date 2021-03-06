const { app, BrowserWindow} = require('electron');
const path = require("path");
const fs = require("fs");

app.disableHardwareAcceleration();

function createWindow () {
  const win = new BrowserWindow({
    width: 720,
    height: 1440,
	resizable: true,
	frame: true,
	title: "Hermes Messenger",
	icon: path.join(__dirname,'../assets/icon.png'),
	webPreferences: {
			preload: path.join(__dirname,'browser.js'),
			nativeWindowOpen: false,
			contextIsolation: false,
			enableRemoteModule: true
		}
  })

  win.loadURL('https://www.messenger.com/login/')

  win.on('page-title-updated', (evt) => {
    evt.preventDefault();
  });

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





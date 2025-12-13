block_cipher = None

# 1. Сборка основного исполняемого файла (app.py)
a = Analysis(['app.py'],
             pathex=['.'],
             binaries=[],
             datas=[],
             hiddenimports=['customtkinter', 'psycopg2'],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)

pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='AirportApp',
          debug=False,
          strip=False,
          upx=True,
          console=False,
          icon=None )
{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/db88608d8c811a93b74c99cfa1224952afc78200";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let
          pkgs = import nixpkgs { inherit system; };
        in
        rec {
          packages.ramble = pkgs.stdenv.mkDerivation {
            name = "ramble";
            src = pkgs.lib.cleanSource ./.;
            nativeBuildInputs = with pkgs; [ scons mpi ];
            buildInputs = with pkgs;[ boost gtest ];
            dontUseSconsInstall = true;
            installPhase = ''
              runHook preInstall
              install -Dm755 ramble "$out/bin/ramble"
              runHook postInstall
            '';
          };
          checks = packages;
          defaultPackage = packages.ramble;
          devShell = pkgs.mkShell {
            inputsFrom = [ packages.ramble ];
          };
        }
      );
}
